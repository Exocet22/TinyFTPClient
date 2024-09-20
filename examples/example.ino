/*****************************************************/
/*                                                   */
/*             Example for TinyFTPClient             */
/*      (c) Yvan Régeard - All rights reserved       */
/*                                                   */
/* Licensed under the MIT license. See LICENSE file  */
/* in the project root for full license information. */
/*                                                   */
/*****************************************************/



// Includes
#include <ESP8266WiFi.h>
#include <FS.h>
#include <FTPClient.h>
#include "octocat.h"



// Constants
#define WIFI_SSID             ""
#define WIFI_PASS             ""
#define FTP_SERVER_ADDRESS    ""
#define FTP_SERVER_PORT       21
#define FTP_USER_NAME         ""
#define FTP_USER_PASSWORD     ""



// Display file system information
void display_file_system_information()
{
  Serial.println("File system:");
  if (SPIFFS.begin())
  {
    // Display files
    Dir directory=SPIFFS.openDir("/");
    while(directory.next())
    {
      File resource_file=directory.openFile("r");
      Serial.printf("%s (%d bytes)\n",directory.fileName().c_str(),resource_file.size());
      resource_file.close();
    }

    // Display space used
    FSInfo fs_info;
    SPIFFS.info(fs_info);
    Serial.printf("Total : %d KBytes\n",fs_info.totalBytes/1024);
    Serial.printf("Used : %d KBytes\n",fs_info.usedBytes/1024);
    Serial.printf("Remaining : %d KBytes\n",fs_info.totalBytes/1024-fs_info.usedBytes/1024);
  }
}



// Initialization
void setup()
{
  // Wait for stable signal
  delay(150);

  // Initialize debug traces
  Serial.begin(115200);
  Serial.println("\n");

  // Debug trace
  Serial.println("****** Upload image application for TinyFTPClient Library ******");

  // Display file system information
  display_file_system_information();

  // Connect to WiFi hotspot
  WiFi.begin( WIFI_SSID, WIFI_PASS );
  Serial.println("Connecting to Wifi hotspot...");
  while (WiFi.status()!=WL_CONNECTED) { Serial.print("o"); delay(500); }

  // Debug trace
  Serial.println("\nConnected");

  // Open FTP connection
  FTPClient ftp_client;
  if (ftp_client.open(FTP_SERVER_ADDRESS,FTP_SERVER_PORT,FTP_USER_NAME,FTP_USER_PASSWORD))
  {
    // Debug trace
    Serial.println("FTP client is connected");

    // Create new directory
    Serial.print("Create directory: ");
    if (ftp_client.create_directory("new_dir")) Serial.println("success");
    else Serial.println("failed");

    // Change directory
    Serial.print("Change directory: ");
    if (ftp_client.change_directory("new_dir")) Serial.println("success");
    else Serial.println("failed");

    // Create new file
    Serial.print("Write to file: ");
    char text_to_write[]="This is a first line\n";
    if (ftp_client.write_file("hello_world.txt",(uint8_t*) text_to_write,strlen(text_to_write)+1)) Serial.println("success");
    else Serial.println("failed");

    // Append data to it
    Serial.print("Append to file: ");
    char text_to_append[]="This is the second line\n";
    if (ftp_client.append_file("hello_world.txt",(uint8_t*) text_to_append,strlen(text_to_append)+1)) Serial.println("success");
    else Serial.println("failed");

    // Create new file again
    Serial.print("Write to file: ");
    if (ftp_client.write_file("octocat.jpg",octocat_pic,sizeof(octocat_pic))) Serial.println("success");
    else Serial.println("failed");

    // Rename it
    Serial.print("Rename file: ");
    if (ftp_client.rename_file("octocat.jpg","octocat_renamed.jpg")) Serial.println("success");
    else Serial.println("failed");

    // Create new file again
    Serial.print("Write to file: ");
    if (ftp_client.write_file("new_file.txt",(uint8_t*) text_to_write,strlen(text_to_write)+1)) Serial.println("success");
    else Serial.println("failed");

    // Read file
    Serial.print("Read file: ");
    char result[128]="";
    if (ftp_client.read_file("new_file.txt",(uint8_t*) result,sizeof(result))) Serial.printf("%s\n",result);
    else Serial.println("failed");

    // Delete it
    Serial.print("Delete file: ");
    if (ftp_client.delete_file("new_file.txt")) Serial.println("success");
    else Serial.println("failed");

    // Get last modified time
    Serial.print("Get last modified time: ");
    char last_modified_time[128]="";
    if (ftp_client.get_last_modified_time("octocat_renamed.jpg",last_modified_time)) Serial.printf("%s\n",last_modified_time);
    else Serial.println("failed");

    // Create new directory
    Serial.print("Create directory: ");
    if (ftp_client.create_directory("new_dir")) Serial.println("success");

    // Remove it
    Serial.print("Remove directory: ");
    if (ftp_client.remove_directory("new_dir")) Serial.println("success");
    else Serial.println("failed");

    // Download file
    Serial.print("Download file: ");
    if (ftp_client.read_file("octocat_renamed.jpg","/octocat.jpg")) Serial.println("success");
    else Serial.println("failed");

    // Upload file
    Serial.print("Upload file: ");
    if (ftp_client.write_file("octocat_big.jpg","/octocat_big.jpg")) Serial.println("success");
    else Serial.println("failed");

    // Display file system information
    display_file_system_information();

    // List directory
    String item_list[128];
    Serial.print("List directory: ");
    if (ftp_client.list_directory("",item_list,128))
    {
      Serial.println("success");
      for(uint8_t i=0; i<128; i++) if (item_list[i].length()) Serial.println(item_list[i]);
    }
    else Serial.println("failed");

    // Close FTP connection
    ftp_client.close();
  }
  else Serial.println("Unable to open a FTP connection");

  // Debug trace
  Serial.println("Done");
}



// Main loop
void loop()
{
  // Do nothing
  yield();
}
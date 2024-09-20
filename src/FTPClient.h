/*****************************************************/
/*                                                   */
/*                   TinyFTPClient                   */
/*      (c) Yvan Régeard - All rights reserved       */
/*                                                   */
/* Licensed under the MIT license. See LICENSE file  */
/* in the project root for full license information. */
/*                                                   */
/*****************************************************/
#ifndef _TINY_FTPCLIENT_H_
#define _TINY_FTPCLIENT_H_



// Constants
#define FTP_CLIENT_DEFAULT_TIMEOUT              10000             // Default timeout: 10 seconds
#define FTP_CLIENT_BUFFER_SIZE                  128               // Internal buffer size: 128 bytes
#define FTP_CLIENT_TRANSFER_BLOCK_SIZE          512               // Block size used during transfer: 512 bytes



// FTPClient class definition
class FTPClient
{
  // Private attributes
  private:

    // Timeout
    uint16_t m_timeout;

    // WiFi client
    WiFiClient m_client;

    // WiFi passive client
    WiFiClient m_passive_client;



  // Public attribute
  public:

    // Last error code
    uint16_t m_last_error_code;



  // Private methods
  private:

    // Run command
    uint16_t run_command(const char* command,const char* param="",char* answer=NULL);

    // Get server answer
    uint16_t get_server_answer(char* answer=NULL);

    // Passive mode
    bool open_passive_mode();
    bool close_passive_mode();
    void receive(uint8_t* buffer,size_t buffer_size);
    void receive(File& destination_file);
    void send(uint8_t* buffer,size_t buffer_size);
    void send(File& source_file);



  // Public methods
  public:

    // Constructor
    FTPClient(uint16_t timeout=FTP_CLIENT_DEFAULT_TIMEOUT);

    // Connection
    bool open(const char* server_address,const uint16_t server_port,const char* user_name,const char* user_password);
    void close();

    // File management
    bool write_file(const char* file_name,uint8_t* buffer,size_t buffer_size);
    bool write_file(const char* file_name,const char* spiffs_file_name);
    bool append_file(const char* file_name,uint8_t* buffer,size_t buffer_size);
    bool append_file(const char* file_name,const char* spiffs_file_name);
    bool read_file(const char* file_name,uint8_t* buffer,size_t buffer_size);
    bool read_file(const char* file_name,const char* spiffs_file_name);
    bool rename_file(const char* from,const char* to);
    bool delete_file(const char* file_name);
    bool get_last_modified_time(const char* file_name,char* result);

    // Directory management
    bool create_directory(const char* directory_name);
    bool remove_directory(const char* directory_name);
    bool change_directory(const char* directory_name);
    bool list_directory(const char* directory_name,String* item_list,uint8_t item_list_count);
};



#endif

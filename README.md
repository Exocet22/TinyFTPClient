# FTP Client for the ESP8266

A FTP-Client for the ESP8266

![GitHub last commit](https://img.shields.io/github/last-commit/justinleahy/ESP8266_FTPClient)

* The main purpose of this library was to upload moisture level values to a json file in a locally hosted FTP server, as seen here https://github.com/justinleahy/arduino-moisture-sensor.

## TODO

- [ ] List Dir contents test with different serves;
- [ ] Implement `FEAT` in order to choose which mode to list dir...
- [x] Implement download;

## Free Website Hosting

* The idea behind this project is to `upload` the picture via FTP making it available on an URL something like: `www.mysite.com/my_picture.jpg`

* This way you don't need to overload the ESP32, your network remains secure, not open to the world, no port forwarding.

* For this example I uploaded the GitHub Octocat to my [000Webhost](https://www.000webhost.com/) hosted webiste, the file is avalable under: `https://my_user.000webhostapp.com/gallery_gen/XxXxXxXx.jpg`

## Limitation

* I was only able to download files up to ~90KB, as I can't see any usage for that, I did not spend extra time, as it's partially working.
* A new example under [download_file.ino](./examples/donload_file/download_file.ino) has been added;
* `ESP.getMaxAllocHeap()` returned limited amount of free memory, therefore the buffer can't hold the entire downloaded file.
  * For this reason I have implemented the last argument of `DownloadFile(const char * filename, unsigned char * buf, size_t length, bool printUART )` which will print the buffer directly to the UART;
  * If required, SPIFFS can be used to save the file.

As mentioned [here](https://github.com/espressif/arduino-esp32/issues/1163) and [here](https://github.com/espressif/esp-idf/issues/3497)

## Upload example

* For the uploading example we will use the GitHub Octocat, which binary file is [here](./src/octocat.h):

 <img src="https://github.githubassets.com/images/modules/logos_page/Octocat.png" alt="Octocat" width="50%"> 
 
* Originally forked from [https://github.com/blackcodetavern/ESP32_FTPClient](https://github.com/blackcodetavern/ESP32_FTPClient)

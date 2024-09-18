# TinyFTPClient

A tiny [Arduino](https://arduino.cc/)/[PlatformIO](https://platformio.org/) library for a FTP client running on ESP8266.

Forked from [https://github.com/justinleahy/ESP8266_FTPClient](https://github.com/justinleahy/ESP8266_FTPClient).
Many thanks to all the authors and contributors !!!

## Installation

### Using the Arduino IDE Library Manager

1. Choose `Sketch` -> `Include Library` -> `Manage Libraries...`
2. Type `TinyFTPClient` into the search box.
3. Click the row to select the library.
4. Click the `Install` button to install the library.

### Using PlatformIO Library Manager

1. Choose `PIO Home` -> `Libraries` -> `Registry`
2. Type `TinyFTPClient` into the search box.
3. Click the row to select the library.
4. Click the `Install` button to install the library.

### Using Git

```sh
cd ~/Documents/Arduino/libraries/
git clone https://github.com/exocet22/TinyFTPClient TinyFTPClient
```

## Examples

See [examples](examples) folder.

## Updates

- 90KB upload limitation fixed.
- Upload/download files directly from SPIFFS.
- Published on PlatformIO registry: [TinyFTPClient library](https://registry.platformio.org/libraries/exocet22/TinyFTPCLient).

## License

This libary is [licensed](LICENSE) under the [MIT Licence](https://en.wikipedia.org/wiki/MIT_License).

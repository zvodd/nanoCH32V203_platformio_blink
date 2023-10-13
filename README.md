
### nanoCH32V203 on PlatformIO
Get Blinken Lights with platform.io build environment on windows

### Install PlatformIO
- See the install guide: https://pio-ch32v.readthedocs.io/en/latest/installation.html
- basicly add the Community-PIO-CH32V platform
`https://github.com/Community-PIO-CH32V/platform-ch32v.git`


### Zadig LibUSB

- If you have installed `WCHISPTool` it should be listed as `USB Module` with the CH344 driver
    ... or something named like that (should have taken a screenshot).

- Otherwise  should be called something like `Unknown Device #1` 

- replace with driver `libusb-win32` or `WinUSB`

- [USBView](https://learn.microsoft.com/en-us/windows-hardware/drivers/debugger/usbview) can be helpful for identifing devices as they are plugged in.


### platform IO env

Add platformio to path ( I save it as `env_platio.cmd` and put that file somewhere on  PATH)
```
set PATH=C:\Users\USER\.platformio\penv\Scripts;%PATH%
```

### install board file
copy `nanoCH32V203.json` to `$HOME/.platformio/platforms/ch32v/boards`

    (Just a modified generic CH32V203C8T6, deleted some lines and changed the upload method to `isp`)

### Build and Upload

From project dir (contains `platformio.ini`)
- build with
```
pio run
```
- upload with
```
pio run --target upload
```


#### Other Code Samples and Guides

https://github.com/wuxx/nanoCH32V203

https://github.com/Community-PIO-CH32V/ch32-pio-projects

https://lykt.xyz/kite/ | https://gitlab.com/lykt/kite

https://theprogrammersreturn.com/riscv/NanoCH32V203.html | https://github.com/doppydoggy23/NanoCH32V203
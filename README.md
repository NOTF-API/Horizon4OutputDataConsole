# Horizon4OutputDataConsole
a simple windows mfc application to watch the Forza Horizon4 Data Output data by using winsocks(UDP)
# reference
+ [bluedoom/FH4RemoteOutput](https://github.com/bluedoom/FH4RemoteOutput)
+ [forzamotorsport:7--Data-Out--feature-details](https://forums.forzamotorsport.net/turn10_postst128499_Forza-Motorsport-7--Data-Out--feature-details.aspx)
# download
[v0.0.1](https://github.com/NOTF-API/Horizon4OutputDataConsole/releases)
# how to use
Steps to configure Rich Presence:
Download the latest release and extract it somewhere on your desktop.

```CheckNetIsolation.exe LoopbackExempt -a -n=Microsoft.SunriseBaseGame_8wekyb3d8bbwe```

*if your game is from UWP,you need to do this,maybe you don't have to do this by using steam*

Run the command above(just use cmd) (only need to run it once per installation of Forza Horizon 4).

In Forza Horizon 4, load into the game world, then go to Settings > HUD and Gameplay and scroll down to the bottom.
+ Set Data Out to On
+ Set Data Out IP Address to 127.0.0.1 (or whatever local IP address is running the application)
+ Set Data Out IP Port to 1234
+ Start the application and press the "start udp server" button
# about bugs
+ server may not be close correctly,causing "bind error"
+ some data([Sept. 10, 2018 UPDATE: NEW DATA OUT STRUCTURE]
V1 is now called Sled
V2 is V1 then these added in this order at the bottom. ) 
can't be convert correctly but I don't know why
+ and so on....

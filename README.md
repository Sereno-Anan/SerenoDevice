# SerenoDevice

> M5StickC と [ELECFREAKS Octopus Rain/Steam Sensor](https://www.elecfreaks.com/octopus-rain-steam-sensor.html) で作る雨滴センサー

## 必要な物

- [Visual Studio Code](https://azure.microsoft.com/ja-jp/products/visual-studio-code/)
  - [Platform IO](https://marketplace.visualstudio.com/items?itemName=platformio.platformio-ide) 拡張機能

## セットアップ

- リポジトリをクローンし，Visual Studio Code で開く

```sh
git clone https://github.com/Sereno-Anan/SerenoDevice.git
cd SerenoDevice
code .
```

- `src/Wi-Fi.cpp` に以下を追加する

```cpp
#include "Wi-Fi.h"

char *wifi_ssid = "test";
char *wifi_password = "test";
char *host_url = "test";
```

- Platform IO でビルドする．

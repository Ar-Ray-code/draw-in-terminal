# Draw on terminal

#### [English]

# My girlfriend doesn't come out of my "Terminal"!

![](screenshot_example/result_exe.png)

## Description

- This program draws images or videos on the terminal.

## Requirement

- Ubuntu18.04 LTS Desktop
- Build:CMake2.8, OpenCV3.2 

## Installation & Usage

#### Installation


```sh
git clone https://github.com/Ar-Ray-code/draw_on_terminal.git
cd draw_on_terminal
mkdir build
cd build
cmake ..
make
```

#### Usage

`./draw_on_terminal <options> <your image or video file>`

e.g. if you have video.mp4, Try to execute `./draw_on_terminal video.mp4`

- The larger the image, the slower the drawing of the terminal. It takes 5 to 10 seconds for a 4K display.

- The size of the output image depends on the width of the terminal.


![](screenshot_example/size_variable.png)

## Options

- --help or -h                      : View help
- --background or -b        : Background is colored.
- --number or -n               : Number is colored.
- --fixed_value or -f           : Output values are fixed at 8.
- --random_value or -r     : Output values are random number.
- --disable_number or -d : Disable output values.
- --gray_enable or -g         : The number is output in grayscale.(In development)

## License

MIT : https://github.com/Ar-Ray-code/draw_on_terminal/blob/main/LICENSE

### [日本語]

# 俺の彼女がターミナルから出てこないんだけど！！

![](screenshot_example/result_exe.png)

## 概要

- ターミナル上に画像や動画を描画します。

## 依存環境・要件

- Ubuntu18.04 LTS (Desktop)
- ビルド：CMake2.8, OpenCV3.2

## インストールと使用方法

#### インストール

```sh
git clone https://github.com/Ar-Ray-code/draw_on_terminal.git
cd draw_on_terminal
mkdir build
cd build
cmake ..
make
```

#### 使用方法

`./draw_on_terminal <options> <your image or video file>`

例えば、video.mp4を持っている場合： `./draw_on_terminal video.mp4`を実行してみてください。

- ターミナルの描画は画像が大きいほど遅くなります。4Kディスプレイだと5秒～10秒かかります。
- 出力画像のサイズは、端末の幅によって異なります。

![](screenshot_example/size_variable.png)


## オプション


- --help or -h                      : ヘルプを確認します。
- --background or -b        : 背景が色付きになります。
- --number or -n               : 番号が色付きになります。
- --fixed_value or -f           : 出力される番号が8で固定されます。
- --random_value or -r     : 出力される番号が乱数になります。
- --disable_number or -d : 番号の出力を無効化します。
- --gray_enable or -g         : グレースケール表示になります。（開発中）

## ライセンス

MIT : https://github.com/Ar-Ray-code/draw_on_terminal/blob/main/LICENSE
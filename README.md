# Draw in terminal

[![CMake](https://github.com/Ar-Ray-code/draw_in_terminal/actions/workflows/cmake.yml/badge.svg)](https://github.com/Ar-Ray-code/draw_in_terminal/actions/workflows/cmake.yml)
![](https://img.shields.io/github/license/Ar-Ray-code/draw_in_terminal)
![](https://img.shields.io/github/forks/Ar-Ray-code/draw_in_terminal)
![](https://img.shields.io/github/stars/Ar-Ray-code/draw_in_terminal)


Draw image or video on terminal.


## Requirement

- Ubuntu20.04 LTS Desktop
- OpenCV

## Installation & Usage

#### Installation

```sh
git clone https://github.com/Ar-Ray-code/draw_in_terminal.git
cd draw_in_terminal
mkdir build
cd build
cmake ..
make
```

#### Usage

`./draw_on_terminal <options> <your image or video file>`

e.g. if you want to draw video.mp4, Run `./draw_in_terminal video.mp4`.

- The larger the image, the slower the drawing of the terminal. It takes 5 to 10 seconds for a 4K display.

- The size of the output image depends on the width of the terminal.

![](screenshot_example/size_variable.png)

Wallpaper (Pronamachan) -> https://pronama.jp/pronama/wallpapers/

## Options

- --help or -h                      : View help
- --background or -b        : Background is colored.
- --number or -n               : Number is colored.
- --fixed_value or -f           : Output values are fixed at 8.
- --random_value or -r     : Output values are random number.
- --disable_number or -d : Disable output values.
- --gray_enable or -g         : The number is output in grayscale.(In development)

![draw_options](screenshot_example/draw_options.png)

## License

![](https://img.shields.io/github/license/Ar-Ray-code/draw_on_terminal)


## About writer

- Ar-Ray : Japanese student.
- Brog(Japanese) : https://ar-ray.hatenablog.com/
- Twitter : https://twitter.com/Ray255Ar

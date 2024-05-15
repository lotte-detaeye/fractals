# fractals

This is a simple program that displays two different kinds of fractals on the screen, using some color.
You can choose between the Mandelbrot set and the Julia set.

To use it:
```sh
git clone https://github.com/lotte-detaeye/fractals.git fractals
cd fractals
cd minilibx-linux
make
cd ..
make
```

Then run the program and enter the right parameters:
```sh
./fractal mandelbrot
```
or
```sh
./fractal julia -0.8 0.156
#       Other xample values for the julia set: 0.285 0.01
```

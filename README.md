# fractals

This is a simple program that displays two different kinds of fractals on the screen, using some color.
You can choose between the Mandelbrot set and the Julia set.

<p align="center">
<img src="https://github.com/user-attachments/assets/f67b444d-cfc6-468c-8dd0-3c89e3b26445" alt="Screenshot1" width="350"/>
<img src="https://github.com/user-attachments/assets/5623a319-96f5-419d-a71e-e1241a0496d8"  alt="Screenshot2" width="350"/>
</p>

To install it:
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
#       Other example values for the julia set: 0.285 0.01
```

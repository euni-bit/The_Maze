# The_Maze

The Maze is a 3D Maze game that uses ray casting to render a 2D map into a 3D navigable world!

The Maze was written was written in C ussing SDL2 library. Deveploment was performed using Ubuntu 24.04 - gcc (Ubuntu 11.3.0-1ubuntu1~22.04) 11.3.0

### About SDL2 

Simple DirectMedia Layer is a cross-platform development library designed to provide low level access to audio, keyboard, mouse, joystick, and graphics hardware via OpenGL and Direct3D. It is used by video playback software, emulators, and popular games including Valve's award winning catalog and many Humble Bundle games.

## Install

Ubuntu: sudo apt-get install libsdl2-dev

Install hombebrew for mac: https://brew.sh/
MacOS: brew install sdl2

SDL website: https://www.libsdl.org/download-2.0.php

## How to play

Install the SDL2 library, clone the repository, then using the MakeFile, you can use the
- make
- make run

commands or by executing the executable (./maze).

- Use up and down arrow keys to move forward and backward (keys w and s serve the same function)
- Use right and left arrow keys to turn the camera arround (keys d and a serve the same function)


## Compilation
```sh
$ gcc -Wall -Werror -Wextra -pedantic ./src/*.c -lm -o maze `sdl2-config --cflags` `sdl2-config --libs`;
```
## Inspiration

The Maze project is a game directly inspired by a famous game: **Wolfeinstein3D**,
Wolfeinstein3D is a game made in 1992, developped by id Software, made without a game engine.

## How to develop without a game engine

To make the game, I used the C language because i already knew some of it, *(I could have tried the C++)*
and the most important thing here was to find **the thing** to be able to do a game without a game engine,
this thing is the SDL library.

For this project, the SDL library was useful for creating a window, rendering things on the window like forms, colors, textures, and taking the user inputs.

SDL site: https://www.libsdl.org/download-2.0.php

## What I could have done more

- I could have implemented an exit to my labyrinth / EndGame
- I could have implemented objects
- I could have implemented enemies (Like Wolfeinstein3D) / gun in players hands
- I could have implemented rain

And so on, only imagination and skills can make it possible.

## Author

Eunielis Serrano <seunielis@gmail.com>
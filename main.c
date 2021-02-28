/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseema <lseema@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 18:42:12 by lseema            #+#    #+#             */
/*   Updated: 2021/02/28 20:20:00 by lseema           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//gcc main.c -lm `SDL/bin/sdl2-config --cflags` -I SDL/include/SDL2 -o main -lm `SDL/bin/sdl2-config --libs`

#include <SDL.h>

#define SCREEN_HEIGHT 800
#define SCREEN_WIDTH 600

int main(int argc, char ** argv)
{
    SDL_Window  *window;
    SDL_Surface *surface;
    SDL_Event   event;
    int         running;


    if (SDL_Init(SDL_INIT_VIDEO))
        return (1);
    if (!(window = SDL_CreateWindow("SDL Test", 0, 0,
        SCREEN_HEIGHT, SCREEN_WIDTH, SDL_WINDOW_SHOWN)))
        return (1);
    SDL_ShowWindow(window);
    surface = SDL_GetWindowSurface(window);
    SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, 0, 255, 0));
    SDL_UpdateWindowSurface(window);

    running = 1;
    while (running)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                running = 0;
            }
        }
        SDL_Delay(32);
    }

    SDL_DestroyWindow(window);
    SDL_Quit();
    return (0);
}

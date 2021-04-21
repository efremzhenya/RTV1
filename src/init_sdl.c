/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sdl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseema <lseema@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 18:42:12 by lseema            #+#    #+#             */
/*   Updated: 2021/04/20 22:00:24 by lseema           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//gcc main.c -lm `SDL/bin/sdl2-config --cflags` -I SDL/include/SDL2 -o main -lm `SDL/bin/sdl2-config --libs`

#include <SDL.h>

int init_sdl(int width, int height)
{
    SDL_Window      *window;
    SDL_Renderer    *ren;
    SDL_Event       event;
    int             running;

    if (SDL_Init(SDL_INIT_VIDEO))
        return (1);
    if (!(window = SDL_CreateWindow("SDL Test", 0, 0,
        width, height, SDL_WINDOW_SHOWN)))
        return (1);
    SDL_ShowWindow(window);
    // surface = SDL_GetWindowSurface(window);
    // SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, 0, 255, 0));
    ren = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    SDL_SetRenderDrawColor(ren, 0x00, 0x00, 0x00, 0x00);
    SDL_RenderClear(ren);
    SDL_SetRenderDrawColor(ren, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderDrawLine(ren, 10, 70, 640 - 10, 70);
    SDL_Rect rect2 = {70, 10, 50, 50};
    SDL_RenderDrawRect(ren, &rect2);
    SDL_RenderPresent(ren);
    //SDL_UpdateWindowSurface(window);

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

    SDL_DestroyRenderer(ren);
    ren = NULL;
    SDL_DestroyWindow(window);
    SDL_Quit();
    return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sdl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseema <lseema@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 18:42:12 by lseema            #+#    #+#             */
/*   Updated: 2021/04/25 17:48:08 by lseema           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//gcc main.c -lm `SDL/bin/sdl2-config --cflags` -I SDL/include/SDL2 -o main -lm `SDL/bin/sdl2-config --libs`

#include "rtv1.h"
#include "scene.h"

t_sdl *init_sdl(int width, int height)
{
    t_sdl   *sdl;

    sdl = (t_sdl*)malloc(sizeof(t_sdl));
    if (SDL_Init(SDL_INIT_VIDEO))
        return (NULL);
    if (!(sdl->win = SDL_CreateWindow("SDL Test", 0, 0, width, height,
        SDL_WINDOW_SHOWN)))
        return (NULL);
    SDL_ShowWindow(sdl->win);
    sdl->ren = SDL_CreateRenderer(sdl->win, -1, SDL_RENDERER_ACCELERATED);
    return (sdl);
}

void    draw(t_sdl *sdl, t_vec3 *framebuff, int h, int w)
{
    int x;
    int y;
    int i;

    SDL_SetRenderDrawColor(sdl->ren, 0x00, 0x00, 0x00, 0x00);
    SDL_RenderClear(sdl->ren);
    y = 0;
    i = 0;
    while (y < h)
    {
        x = 0;
        while (x < w)
        {
            SDL_SetRenderDrawColor(sdl->ren, framebuff[i].x, framebuff[i].y, framebuff[i].z, 255);
            SDL_RenderDrawPoint(sdl->ren, x, y);
            x++;
            i++;
        }
        y++;
    }
    SDL_RenderPresent(sdl->ren);
}


void    main_loop(t_sdl *sdl, t_scene *scene)
{
    int         running;
    SDL_Event   event;
    t_vec3      *framebuff;

    framebuff = NULL;
    if (scene != NULL)
        framebuff = ray_trace(scene);
    running = 1;
    draw(sdl, framebuff, scene->height, scene->width);
    while (running)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                running = 0;
            }
        }
        SDL_Delay(300);
    }
}

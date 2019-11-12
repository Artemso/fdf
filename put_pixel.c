// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   put_pixel.c                                        :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2019/11/08 11:33:50 by asolopov          #+#    #+#             */
// /*   Updated: 2019/11/12 13:53:58 by asolopov         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "fdf.h"

// void line(int startx, int starty, int endx, int endy, void	*mlx_ptr, void	*win_ptr) {
//     int t, distance;
//     int xerr=0, yerr=0, delta_x, delta_y;
//     int incx, incy;
 
//     /* compute the distances in both directions */
//     delta_x=endx-startx;
//     delta_y=endy-starty;
 
//     /* Compute the direction of the increment,
//        an increment of 0 means either a horizontal or vertical
//        line.
//     */
//     if(delta_x>0) incx=1;
//     else if(delta_x==0) incx=0;
//     else incx=-1;
 
//     if(delta_y>0) incy=1;
//     else if(delta_y==0) incy=0;
//     else incy=-1;
 
//     /* determine which distance is greater */
//     delta_x=abs(delta_x);
//     delta_y=abs(delta_y);
//     if(delta_x>delta_y) distance=delta_x;
//     else distance=delta_y;
 
//     /* draw the line */
//     for(t=0; t<=distance+1; t++) {
//         mlx_pixel_put(mlx_ptr, win_ptr, startx, starty, 16737535);
         
//         xerr+=delta_x;
//         yerr+=delta_y;
//         if(xerr>distance) {
//             xerr-=distance;
//             startx+=incx;
//         }
//         if(yerr>distance) {
//             yerr-=distance;
//             starty+=incy;
//         }
//     }
// }

// int	main(void)
// {
// 	void	*mlx_ptr;
// 	void	*win_ptr;
// 	int x1;
// 	int y1;
// 	int x2;
// 	int y2;

// 	x1 = 10;
// 	y1 = 80;
// 	x2 = 80;
// 	y2 = 10;
// 	mlx_ptr = mlx_init();
// 	win_ptr = mlx_new_window(mlx_ptr, 100, 100, "Artem's window");
// 	mlx_pixel_put(mlx_ptr, win_ptr, x1, y1, 16737535);
// 	mlx_pixel_put(mlx_ptr, win_ptr, x2, y2, 16737535);
// 	line(x1, y1, x2, y2, mlx_ptr, win_ptr);

// 	mlx_loop(mlx_ptr);
// 	return (0);
// }

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_rainbow.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nando <nando@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 19:39:53 by nando             #+#    #+#             */
/*   Updated: 2025/04/16 19:55:33 by nando            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "../create_trgb/create_trgb.c"
 
int hsv_to_rgb(double hue)
{
    double c = 1.0;                     // v*s = 1*1 = 1
    double x = c * (1.0 - fabs(fmod(hue / 60.0, 2) - 1));
    double r1, g1, b1;

    if (hue < 60)
    {
        r1 = c;
        g1 = x;
        b1 = 0;
    }
    else if (hue < 120)
    {
        r1 = x;
        g1 = c;
        b1 = 0;
    }
    else if (hue < 180)
    {
        r1 = 0;
        g1 = c;
        b1 = x;
    }
    else if (hue < 240)
    {
        r1 = 0;
        g1 = x;
        b1 = c;
    }
    else if (hue < 300)
    {
        r1 = x;
        g1 = 0;
        b1 = c;
    }
    else
    {
        r1 = c;
        g1 = 0;
        b1 = x;
    }
    int r = (int)(r1 * 255);
    int g = (int)(g1 * 255);
    int b = (int)(b1 * 255);

    return create_trgb(0, r, g, b);
}


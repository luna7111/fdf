/* ************************************************************************** */
/*                                                                            */
/*                                                    _.._  .           .     */
/*   hooks.h                                        .' .-'`        *          */
/*                                                 /  /       +        *      */
/*   By: ldel-val <ldel-val@student.42madrid.com>  |  |           *           */
/*                                                 \  '.___.;       +         */
/*   Created: 2024/12/22 13:18:56 by ldel-val       '._  _.'   .        .     */
/*   Updated: 2025/02/06 18:24:11 by ldel-val          ``                     */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOKS_H
# define HOOKS_H

# define M_UP 4
# define M_DOWN 5
# define K_ESC 65307
# define K_LEFT 65361
# define K_UP 65362
# define K_RIGHT 65363
# define K_DOWN 65364
# define K_P 112
# define K_X 120
# define K_Y 121
# define K_Z 122

int	key_hook(int keycode, t_data *data);
int	mouse_hook(int keycode, int x, int y, t_data *data);
int	safe_close(t_data *data);

#endif

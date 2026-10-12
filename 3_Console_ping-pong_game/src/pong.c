#include <stdio.h>

int way(int flag, int move, int x_old, int y_old);
int platform_way(int flag, char button, int y_rigth_platform_center, int y_left_platform_center);
int ball(int flag, int current_move, int x_ball, int y_ball, int y_rigth_platform_center,
         int y_left_platform_center, int count_right, int count_left);
void draw_field(int x_ball, int y_ball, int y_rigth_platform_center, int y_left_platform_center,
                int count_right, int count_left);

int main() {
    int current_move = 1;
    int y_rigth_platform_center = 13;
    int y_left_platform_center = 13;
    int x_ball = 40;
    int y_ball = 13;
    char button;
    int count_right = 0;
    int count_left = 0;
    while (1) {
        scanf("%c", &button);
        if ((button == 'A') || (button == 'Z') || (button == 'K') || (button == 'M') || (button == ' ')) {
            y_rigth_platform_center =
                platform_way(0, button, y_rigth_platform_center, y_left_platform_center);
            y_left_platform_center = platform_way(1, button, y_rigth_platform_center, y_left_platform_center);
            if (y_rigth_platform_center < 2) y_rigth_platform_center = 2;
            if (y_rigth_platform_center > 24) y_rigth_platform_center = 24;
            if (y_left_platform_center < 2) y_left_platform_center = 2;
            if (y_left_platform_center > 24) y_left_platform_center = 24;
            current_move = ball(0, current_move, x_ball, y_ball, y_rigth_platform_center,
                                y_left_platform_center, count_right, count_left);
            int new_x = ball(1, current_move, x_ball, y_ball, y_rigth_platform_center, y_left_platform_center,
                             count_right, count_left);
            int new_y = ball(2, current_move, x_ball, y_ball, y_rigth_platform_center, y_left_platform_center,
                             count_right, count_left);
            count_right = ball(3, current_move, x_ball, y_ball, y_rigth_platform_center,
                               y_left_platform_center, count_right, count_left);
            count_left = ball(4, current_move, x_ball, y_ball, y_rigth_platform_center,
                              y_left_platform_center, count_right, count_left);
            x_ball = new_x;
            y_ball = new_y;
            draw_field(x_ball, y_ball, y_rigth_platform_center, y_left_platform_center, count_right,
                       count_left);
            if (count_left >= 21 || count_right >= 21) {
                break;
            }
        }
    }
    return 0;
}

int way(int flag, int move, int x_old, int y_old) {
    int x_new = x_old, y_new = y_old;
    int res;
    if (move == 1) {
        x_new++;
    } else if (move == 2) {
        x_new--;
    } else if (move == 3) {
        x_new++;
        y_new++;
    } else if (move == 4) {
        x_new--;
        y_new++;
    } else if (move == 5) {
        x_new++;
        y_new--;
    } else if (move == 6) {
        x_new--;
        y_new--;
    }
    if (flag == 0)
        res = x_new;
    else
        res = y_new;

    return res;
}

int platform_way(int flag, char button, int y_rigth_platform_center, int y_left_platform_center) {
    int res;
    if (button == ' ') {
        if (flag == 0)
            return y_rigth_platform_center;
        else
            return y_left_platform_center;
    }
    if (button == 'K')
        y_rigth_platform_center++;
    else if (button == 'M')
        y_rigth_platform_center--;
    else if (button == 'A')
        y_left_platform_center++;
    else if (button == 'Z')
        y_left_platform_center--;

    if (flag == 0)
        res = y_rigth_platform_center;
    else
        res = y_left_platform_center;
    return res;
}

int get_wall_move(int current_move, int x_ball, int next_x, int next_y) {
    int res = current_move;
    if (next_y >= 26) {
        if (x_ball < next_x) {
            res = 5;
        } else {
            res = 6;
        }
    } else if (next_y <= 0) {
        if (x_ball < next_x) {
            res = 3;
        } else
            res = 4;
    }
    return res;
}

int get_left_platform_move(int y_ball, int y_left) {
    int res = 2;
    if (y_ball == y_left) res = 1;
    if (y_ball == y_left + 1) res = 3;
    if (y_ball == y_left - 1) res = 5;
    return res;
}

int get_right_platform_move(int y_ball, int y_right) {
    int res = 1;
    if (y_ball == y_right) res = 2;
    if (y_ball == y_right + 1) res = 4;
    if (y_ball == y_right - 1) res = 6;
    return res;
}

int get_flag_value(int flag, int res, int move, int x, int y, int c_right, int c_left) {
    int n = res;
    if (flag == 0) n = move;
    if (flag == 1) n = x;
    if (flag == 2) n = y;
    if (flag == 3) n = c_right;
    if (flag == 4) n = c_left;
    return n;
}

int ball(int flag, int current_move, int x_ball, int y_ball, int y_rigth_platform_center,
         int y_left_platform_center, int count_right, int count_left) {
    int res = 0, new_move = current_move;
    int next_x = way(0, current_move, x_ball, y_ball);
    int next_y = way(1, current_move, x_ball, y_ball);
    int new_count_right = count_right, final_x = x_ball;
    int new_count_left = count_left, final_y = y_ball;
    new_move = get_wall_move(current_move, x_ball, next_x, next_y);
    if (new_move != current_move) {
        next_x = way(0, new_move, x_ball, y_ball);
        next_y = way(1, new_move, x_ball, y_ball);
    }
    if (next_x <= 5) {
        new_move = get_left_platform_move(y_ball, y_left_platform_center);
        if (new_move == 2 && y_ball != y_left_platform_center) {
            new_count_right++;
            final_x = 40;
            final_y = 13;
            res = get_flag_value(flag, res, new_move, final_x, final_y, new_count_right, new_count_left);
        }
        next_x = way(0, new_move, x_ball, y_ball);
        next_y = way(1, new_move, x_ball, y_ball);
    }
    if (next_x >= 75) {
        new_move = get_right_platform_move(y_ball, y_rigth_platform_center);
        if (new_move == 1 && y_ball != y_rigth_platform_center) {
            new_count_left++;
            final_x = 40;
            final_y = 13;
            res = get_flag_value(flag, res, new_move, final_x, final_y, new_count_right, new_count_left);
        }
        next_x = way(0, new_move, x_ball, y_ball);
        next_y = way(1, new_move, x_ball, y_ball);
    }
    if (final_x == x_ball && final_y == y_ball) {
        final_x = next_x;
        final_y = next_y;
    }

    return get_flag_value(flag, res, new_move, final_x, final_y, new_count_right, new_count_left);
}

void draw_field(int x_ball, int y_ball, int y_right_platform_center, int y_left_platform_center,
                int count_right, int count_left) {
    int x, y;
    char pixel;

    printf("\033[2J\033[H");

    printf("Score Left: %d | Right: %d\n", count_left, count_right);

    for (y = 26; y >= 0; y--) {
        for (x = 0; x < 80; x++) {
            pixel = ' ';

            if (y == 26 || y == 0) {
                pixel = '-';
            } else if (x == 40) {
                pixel = '|';
            } else if (x == 5 && y >= y_left_platform_center - 1 && y <= y_left_platform_center + 1) {
                pixel = '|';
            } else if (x == 75 && y >= y_right_platform_center - 1 && y <= y_right_platform_center + 1) {
                pixel = '|';
            }

            if (x == x_ball && y == y_ball) {
                pixel = 'o';
            }
            printf("%c", pixel);
        }
        printf("\n");
    }
    if (count_left >= 21 || count_right >= 21) {
        printf("\033[2J\033[H");
        printf("\nGAME OVER! Score: Left=%d Right=%d\n", count_left, count_right);
    }
}

#include <stdio.h>

int main()
{
    int image[12][12][3], color_count[5] = {0}; // Array para armazenar os valores de cor RGB e contador de cores
    int i, j, num_column_input = 0, num_line_input = 0;
    int index_resume[12][5] = {{0}};
    int rgb_colors[5][3] = {{0, 0, 0}, {255, 0, 0}, {0, 255, 0}, {0, 0, 255}, {255, 255, 0}};
    scanf("P3 %d %d 255", &num_column_input, &num_line_input);

    //
    // Lendo os valores de cor
    for (i = 0; i < num_line_input; i++)
    {
        for (j = 0; j < num_column_input; j++)
        {
            scanf("%d %d %d", &image[i][j][0], &image[i][j][1], &image[i][j][2]);
        }
    }

    // Comprimindo as cores em cada linha e montando a matriz
    for (i = 0; i < num_line_input; i++)
    {
        for (j = 0; j < num_column_input; j++)
        {
            if (image[i][j][0] == 0 && image[i][j][1] == 0 && image[i][j][2] == 0)
            {
                index_resume[i][0]++;
                color_count[0]++;
            }
            else if (image[i][j][0] == 255 && image[i][j][1] == 0 && image[i][j][2] == 0)
            {
                index_resume[i][1]++;
                color_count[1]++;
            }
            else if (image[i][j][0] == 0 && image[i][j][1] == 255 && image[i][j][2] == 0)
            {
                index_resume[i][2]++;
                color_count[2]++;
            }
            else if (image[i][j][0] == 0 && image[i][j][1] == 0 && image[i][j][2] == 255)
            {
                index_resume[i][3]++;
                color_count[3]++;
            }
            else if (image[i][j][0] == 255 && image[i][j][1] == 255 && image[i][j][2] == 0)
            {
                index_resume[i][4]++;
                color_count[4]++;
            }
        }
    }

    for (i = 0; i < num_line_input; i++)
    {
        for (j = 0; j < 5; j++)
        {
            printf("%d ", index_resume[i][j]);
        }
        printf("\n");
    }

    // Determinando a cor predominante
    int predominant_color_index = 0;
    for (i = 1; i < 5; i++)
    {
        if (color_count[i] > color_count[predominant_color_index])
        {
            predominant_color_index = i;
        }
    }

    int colors_index[5] = {-1};
    int z = 0;
    for (i = 0; i < 5; i++)
    {
        if (color_count[predominant_color_index] == color_count[i])
        {
            colors_index[z] = i;
            z++;
        }
    }

    if (!(color_count[0] == color_count[1] && color_count[1] == color_count[2] && color_count[2] == color_count[3] && color_count[3] == color_count[4]))
    {
        if (z < 2)
        {
            for (i = 0; i < num_line_input; i++)
            {
                for (j = 0; j < num_column_input; j++)
                {

                    if (image[i][j][0] == rgb_colors[predominant_color_index][0] && image[i][j][1] == rgb_colors[predominant_color_index][1] &&
                        image[i][j][2] == rgb_colors[predominant_color_index][2])
                    {
                        image[i][j][0] = 0;
                        image[i][j][1] = 0;
                        image[i][j][2] = 0;
                    }
                    else
                    {
                        image[i][j][0] = 255;
                        image[i][j][1] = 255;
                        image[i][j][2] = 255;
                    }
                }
            }
        }
        else
        {
            for (i = 0; i < num_line_input; i++)
            {
                for (j = 0; j < num_column_input; j++)
                {
                    // Verifica se a cor atual está entre as cores majoritárias
                    int is_major_color = 0;
                    for (int k = 0; k < z; k++)
                    {
                        if (image[i][j][0] == rgb_colors[colors_index[k]][0] &&
                            image[i][j][1] == rgb_colors[colors_index[k]][1] &&
                            image[i][j][2] == rgb_colors[colors_index[k]][2])
                        {
                            is_major_color = 1;
                            break;
                        }
                    }

                    // Se a cor não estiver entre as cores majoritárias, substitui por 255 255 255
                    if (!is_major_color)
                    {
                        image[i][j][0] = 255;
                        image[i][j][1] = 255;
                        image[i][j][2] = 255;
                    }
                }
            }
        }
        // Substituindo as cores dos pixels de cada linha pela cor predominante
    }

    // Exibindo a imagem com as cores substituídas
    for (i = 0; i < num_line_input; i++)
    {
        for (j = 0; j < num_column_input; j++)
        {
            printf("%d %d %d ", image[i][j][0], image[i][j][1], image[i][j][2]);
        }
        printf("\n");
    }

    return 0;
}

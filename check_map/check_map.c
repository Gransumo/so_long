#include "../so_long.h"

int			check_valid_path(t_map *map_info);
void		init_mapvars(t_map *map);

static int	first_last_line(char *line)
{
	int i;

	i = 0;
	while (line[i] != '\n'  && line[i] != '\0')//si es la primera o la ultima linea tiene que ser TODO 1
	{
		if(line[i] != '1')//si encuentra un caracter distinto de 1 retorno 0
			return (0);
		i++;
	}
	return (i);
}

static int	check_map_values(t_map *map_info)
{
	if(map_info->n_C < 1) // tiene que haber como minimo 1 coleccionable
		return(error("COLLECTABLE NOT FOUND"));
	if(map_info->n_E < 1) // tiene que haber como minimo una salida
		return(error("EXIT NOT FOUND"));
	if(map_info->n_E > 1 ) // solo puede haber como maximo una salida
		return(error("THERE CAN ONLY ONE EXIT CHARACTER"));
	if(map_info->n_P < 1) // Tiene que haber como minimo un jugador
		return(error("PLAYER NOT FOUND"));
	if(map_info->n_P > 1) // Como máximo un jugador
		return(error("THERE CAN ONLY BE ONE PLAYER"));
	return (1);
}

static int	check_line(char	*line, t_map *map_info, int index)
{
	int		i;

	if((index == 0 || index == map_info->n_lines - 1) && first_last_line(line) == 0)//verifico si es la primera o la ultima linea
		return (error("THE MAP HAS TO BE SURRONDER BY WALLS"));
	if(ft_strlen_linemap(line) != map_info->len_x)// verifico si el largo de la linea es igual a la primera, asi verificoo que sea un mapa rectangular
		return (error("THE MAP HAS TO BE RECTANGULAR"));	
	i = 0;
	while (line[i] != '\0' && line[i] != '\n')
	{
		if((i == 0 || i == map_info->len_x - 1) && line[i] != '1')
			return (error("THE MAP HAS TO BE SURRONDER BY WALLS"));//verifico que el primer y el ultimo caracter de cada linea sea 1
		if(line[i] == 'C') //registro los caracteres encontrados
			map_info->n_C++;
		else if(line[i] == 'E')
			map_info->n_E++;
		else if (line[i] == 'P')
			map_info->n_P++;
		else if (!ft_strchr("CEP10", line[i]))
			return (error("INVALID CHARACTER HAS BEEN FOUND ON THE MAP"));
		i++;
		
	}
	return (1);
}

int	valid_file(int argc, char *argv)
{
	if (argc == 1)
		return (error("NO ARGS"));
	if(argc > 2)
		print_warning("ONLY WILL BE USED THE FIRST ARGUMENT");
	if(ft_strcmp_end(argv, ".ber") == 0)
		return(error("THE FILE SHOULD BE A .ber FILE"));
	return(1);
}

void f_print_map(char **map)// BORRAR!!!!!
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (map[i])
	{
		while (map[i][j] != '\0')
		{
			ft_printf("%c", map[i][j]);
			j++;
		}
		j = 0;
		i++;
	}
	ft_printf("\n\n");
}

int	check_map_rules(char **map)
{
	t_map	*map_info;		//Con esta variable (t_map) voy a ir verificando la informacion del mapa
	int		i;

	i = 0;
	map_info = malloc(sizeof(t_map));
	if (!map_info)
		return (error("ERROR ALLOCATING"));
	map_info->mapp = map;
	init_mapvars(map_info); //Inicializo las variables del mapa
	while (map_info->mapp[i] != NULL)	//Si algun line_len es diferente a la primera el mapa no es rectangular
	{
		if(check_line(map_info->mapp[i], map_info, i) == 0) //paso un puntero de la linea, la estructuda del mapa y el indice de la linea
			return (0);
		i++;
	}
	if(check_map_values(map_info) == 0 || check_valid_path(map_info) == 0) // verifico que los valores sean validos
	{
		free(map_info);
		ft_free_map(map);
		return (0);
	}
	free(map_info);
	ft_free_map(map);
	return (1);
}

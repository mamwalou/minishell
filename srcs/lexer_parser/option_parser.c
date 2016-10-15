#include "../../includes/minishell.h"

int			option_ctrl(t_data *data, t_memory *memory, char **line)
{
	int		count;
	int		sav_pose;
	int		count_space;

	count = 1;
	count_space = 0;
	sav_pose = memory->pos;
	if (line[memory->pos][0] == '"')
	{
		while (line[sav_pose][count])
		{
			if (line[sav_pose][count] == "'")
				;
			count++;
		}
	}
	data->option = init_option(*line, data->option);
}

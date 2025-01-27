#include "pipex.h"

void    f()
{
    system("leaks pipex");
}

int main(int ac, char **av, char **env)
{
    t_parsed_data	data;
    pid_t			child_process1;
    pid_t			child_process2;
    int				pipe_fds[2];

    //atexit(f);
    // parse
    data = parse_data(ac, av, env);
    // pipe
    create_pipe(pipe_fds);
    // children
    create_children(&child_process1, &child_process2, pipe_fds);
    // tasks distribution
    if (child_process1 == 0)
        child1(pipe_fds, data);
    if (child_process2 == 0)
        child2(pipe_fds, data);
    // no leaks
    close(pipe_fds[0]);
    close(pipe_fds[1]);
    wait(NULL);
    wait(NULL);
	free_split(data.cmd1, 0);
	free_split(data.cmd2, 0);
    return (0);
}

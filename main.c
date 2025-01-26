#include "pipex.h"

int main(int ac, char **av, char **env)
{
    t_parsed_data	data;
    pid_t			child_process1;
    pid_t			child_process2;
    int				pipe_fds[2];

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
    close(pipe_fds[READ_IDX]);
    close(pipe_fds[WRITE_IDX]);
    wait(NULL);
    wait(NULL);
    printf("done\n");
    return (0);
}

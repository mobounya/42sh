/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forty_two_sh.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobounya <mobounya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 10:17:07 by ylagtab           #+#    #+#             */
/*   Updated: 2021/05/20 17:25:19 by mobounya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORTY_TWO_SH_H
# define FORTY_TWO_SH_H

# include <sys/wait.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <signal.h>

# include "../libft/libft.h"
# include "constants.h"
# include "typedefs.h"
# include "../src/errors/errors.h"
# include "../src/parser/parser.h"
# include "../src/expansion/expansion.h"
# include "../src/env/env.h"
# include "../src/builtins/builtins.h"
# include "../readline/readline.h"

# define LOW_D_FLAG 0
# define LOW_L_FLAG 1
# define LOW_R_FLAG 3
# define LOW_T_FLAG 4
# define LOW_A_FLAG 0
# define LOW_F_FLAG 1
# define UPP_P_FLAG 2
# define LOW_P_FLAG 3
# define LOW_T_FLAG 4

/*
**	Flags and macros for test builtin
*/

typedef int			t_flag_matcher();
typedef struct s_flags_matcher {
	char			*flag_name;
	t_flag_matcher	*function;
	int				flag;
}					t_flags_matcher;

# define TEST_UNARY_OPERATORS_SIZE 15

# define BLOCK_FILE 1
# define CHARACTER_FILE 2
# define DIRECTORY 3
# define REGULAR_FILE 4
# define GROUP_ID 5
# define SYM_LINK 6
# define NAMED_PIPE 7
# define IS_READABLE 8
# define IS_SOCKET 9
# define POS_SIZE 10
# define USER_ID 11
# define IS_WRITABALE 12
# define IS_EXECUTABLE 13
# define IS_EXIST 15

/*
**	Flags and macros for hash builtin
*/

# define HASH_SIZE		10000

# define DEFAULT_FORMAT		5
# define REUSABLE_FORMAT	6
# define LOCATION_FORMAT	7

/*
**	Flags and macros for type builtin
*/

# define WORD_OUTPUT 5
# define DEFAULT_OUTPUT 6

# define ALIAS 7
# define KEYWORD 8
# define FUNCTION 9
# define BUILTIN 10
# define FILE 11
# define HASH 12

typedef struct s_hash
{
	unsigned int	hits;
	char			*binary;
	char			*path;
}	t_hash;

t_hash				*g_hash[HASH_SIZE];

extern t_vector		*g_shell_env;
extern int			g_exit_status;
extern int			g_term_fd;
extern t_vector		*g_job_list;
extern t_vector		*g_stopped_jobs;
extern t_bool		g_is_job_enabled;

int					ft_tcsetpgrp(int fildes, pid_t pgid_id);
void				del_token(void *element);
void				del_redirection(void *element);
void				del_var(void *element);

/*
** ================================ jobs =======================================
*/

t_job				*new_job(t_bool is_background, char *job_name);
int					wait_job(t_job *job);
void				init_jobs(void);
void				add_process_to_job(t_job *job, pid_t pid);
t_process			*get_process_from_job(t_job *job, pid_t pid);
void				remove_process_from_job(t_job *job, pid_t pid);
void				add_to_job_list(t_job *job);
t_job				*get_job_by_id(u_int32_t id);
void				remove_from_job_list(u_int32_t job_id);
void				update_stopped_jobs(t_job *job);
void				update_job_state(t_job *job, pid_t pid, int wait_status);
void				update_job(t_job *job);
void				update_all_jobs(void);
void				print_job(t_job *job, t_job_print_mode mode,
						t_special_jobs *special_jobs);
void				notify_job_state(void);
t_job				*get_previous_job(void);
t_job				*get_current_job(void);
t_job				*get_job_by_selector(char *job_selector);
int					execute_job(t_vector *pids_vec, char *job_name,
						t_bool is_background);
int					ft_fg(char **args);
int					ft_bg(char **args);
int					ft_jobs(char **args);
void				set_process_group(pid_t pid, pid_t *pgid,
						t_bool is_background);
t_vector			*pid2vec(pid_t pid);
void				print_signal(int ret_status);

/*
** ============================= end jobs ======================================
*/

/*
** ================================ execution ==================================
*/

int					do_redirections(t_vector *red);
int					ft_error(char *str);
int					do_pipes_and_red(int i, int len, t_vector *red);
char				*get_full_path(char *cmd);
void				handle_quotes(char c, int *balance);
void				remove_quotes(char **str);
void				execute_commands(t_vector *commands);
int					execute_simple_cmd(t_simple_command *simple_cmd,
						t_bool is_background);
int					execute_logic_seq(t_logic_sequence *logic_seq,
						t_bool is_background);
int					execute_pipe_seq(t_pipe_sequence *pipe_seq,
						t_bool is_background);
int					get_exit_code(int wait_status);
int					wait_children(pid_t ret_pid);
void				execute_builtins(char **cmd, t_vector *red);
int					check_builtins(char *cmd);
void				remove_quotes_from_args(char **args);
void				reset_signals(void);
int					manage_pipes(int i);
char				*try_every_possibility(char *cmd, char *path_env);

/*
** ============================= end execution =================================
*/

void				do_value(t_vector *values, size_t args_len, t_vector **env);
int					do_tree(char *word, char *flag);
int					do_tests(int i, int is_not, char **cmd);
int					is_correct_path(char *path, int print_error);
char				*concat_path_with_cdpath(char *path);
int					ft_cd(char **cmd);
int					get_next_line(int fd, char **line);
void				backups(int f);
int					check_nbr(char *str, t_bool stat, int f);
int					jhin(char **cmd);
int					check_is_not(int ret, int is_not);
int					ft_echo(char **cmd, t_vector *red);
int					export(char **av);
void				ft_exit(char **cmd);

// char		*ft_strnjoin(char **strings, int n);
// int			ft_isinstr(char c, const char *s);
// char		*ft_skip_unitl_char(const char *str, const char *compare,
// 				int (*f)(int));

/*
**		free functions
*/

void				del_arg(void *el);
void				del_token(void *element);
void				del_redirection(void *element);
void				del_var(void *element);
void				free_simple_cmd(void *elem);
void				free_pipe_seq(void *elem);
void				free_logic_seq(void *elem);
void				free_command(void *elem);

/*
** Prompt
*/

char				*prompt_1(void);

/*
** read
*/

char				*read_cmd_multiline(void);

/*
** Utils
*/

t_bool				is_quote(char c);
t_bool				quote_type(char c);
int					is_close_red(t_redirection *red);
int					sh_system(char *line);
char				*remove_quotes_from_word(char *word);
int					is_space(char c, int quote);

/*
** Signals
*/
void				reset_signals(void);
void				setup_disabled_job_signals(void);
void				setup_enabled_job_signals(void);

/*
**	Functions in hash folder for the hash table and builtin hash
*/

void				ft_add_hash(char *binary, char *path, int increment_hits);
int					ft_hash(char **command);
unsigned long		hash_str(char *str);
int					ft_forget_name(char *name);
int					ft_forget_names(char **names);
char				*ft_get_hash_location(char *name);
void				ft_empty_hash(void);
size_t				ft_get_hash_size(void);
t_hash				*ft_new_hash(char *binary, char *path);
void				ft_print_default_output(uint hits, char *location);
int					ft_print_reusable_output(char *name, char *location);
int					ft_print_location(char *name, char *location);
void				ft_print_all(int format);
int					ft_print_names(char **names, int format);
void				ft_hash_error(char *flag);
int					ft_hash_names(char **names);
char				**ft_parse_options(char **command, int *flag);
void				ft_hash_arg_error(char *flag);
void				ft_hash_flag_error(char *flag);
void				ft_name_not_found(char *name);
char				*ft_get_hash(char *bin);
void				ft_print_chars(char c, uint times);
void				ft_free_hash(t_hash *hash[]);

/*
**	Functions for the type builtin
*/

int					ft_type(char **command);
int					get_cmdtype(char *name, char **val);
int					is_keyword(char *name);
char				*is_hashed(char *name);
char				*is_binary(char *name);
char				*is_alias(char *name);
int					ft_parse_type_options(char *value, unsigned int *flag);
void				ft_display_type_usage(void);
void				ft_type_invalid_option(char option);
int					ft_print_type_hash(char *name, char *path, int format);
int					ft_print_type_alias(char *name, \
					char *alias_value, int format);
int					ft_print_type_keyword(char *name, int format);
int					ft_print_type_builtin(char *name, int format);
int					ft_print_type_binary(char *name, char *path, int format);
int					default_lookup(char *name, int format);
int					lookup_all_types(char	*name, int format);
int					ft_type_check_if_file(char *name, int flag);
int					ft_type_force_path_search(char *name, int flag);
void				ft_type_not_found(char *name);
int					ft_execute_type(char **names, int flag);

/*
**	Functions for the test builtin
*/

int					ft_test(char **command);
int					ft_check_file_type(char *filename, int flag);
int					ft_check_str_length(char *str, int flag);
int					ft_check_file_type(char *filename, int flag);
void				ft_test_condition_expected(char *condition);
int					ft_test_too_many_arguments(void);
int					ft_test_binary_op_expected(char *op);
int					ft_test_unary_op_expected(char *op);
int					ft_test_integer_expected(char *str);
int					is_string_operator(char *operator);
int					is_integer_operator(char *operator);
int					is_unary_operator(char *operator);
int					do_operation(char **command);
int					is_string_operator(char *operator);
int					is_integer_operator(char *operator);
int					is_unary_operator(char *operator);
int					ft_check_file(char *filename, int flag);

#endif

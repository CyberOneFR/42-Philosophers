HEADERS =	\
	-I./headers/

SRCS =	\
	./srcs/init/data_init.c\
	./srcs/init/thread_join.c\
	./srcs/init/populate.c\
	./srcs/init/mutex_init.c\
	./srcs/routine/thread_routine.c\
	./srcs/utils/philo_stop.c\
	./srcs/utils/print_nbr.c\
	./srcs/utils/cleanup.c\
	./srcs/utils/delta_utime.c\
	./srcs/utils/plog.c\
	./srcs/utils/dsleep.c\
	./srcs/utils/check_death.c\
	./srcs/utils/salloc.c\
	./srcs/utils/parsing.c\
	./srcs/main.c\
	./srcs/simulation.c

OBJS =	\
	./build/data_init.o\
	./build/thread_join.o\
	./build/populate.o\
	./build/mutex_init.o\
	./build/thread_routine.o\
	./build/philo_stop.o\
	./build/print_nbr.o\
	./build/cleanup.o\
	./build/delta_utime.o\
	./build/plog.o\
	./build/dsleep.o\
	./build/check_death.o\
	./build/salloc.o\
	./build/parsing.o\
	./build/main.o\
	./build/simulation.o

DEPS =	\
	./build/data_init.d\
	./build/thread_join.d\
	./build/populate.d\
	./build/mutex_init.d\
	./build/thread_routine.d\
	./build/philo_stop.d\
	./build/print_nbr.d\
	./build/cleanup.d\
	./build/delta_utime.d\
	./build/plog.d\
	./build/dsleep.d\
	./build/check_death.d\
	./build/salloc.d\
	./build/parsing.d\
	./build/main.d\
	./build/simulation.d

$(BUILD_DIR):
	@mkdir -p $@

./build/data_init.o: ./srcs/init/data_init.c | $(BUILD_DIR)
	@$(CC) $(CFLAGS) $(HEADERS) -MD -MP -o $@ -c $<
	@echo -e $(BLUE)$(NAME)$(RESET) compiling: $@

./build/thread_join.o: ./srcs/init/thread_join.c | $(BUILD_DIR)
	@$(CC) $(CFLAGS) $(HEADERS) -MD -MP -o $@ -c $<
	@echo -e $(BLUE)$(NAME)$(RESET) compiling: $@

./build/populate.o: ./srcs/init/populate.c | $(BUILD_DIR)
	@$(CC) $(CFLAGS) $(HEADERS) -MD -MP -o $@ -c $<
	@echo -e $(BLUE)$(NAME)$(RESET) compiling: $@

./build/mutex_init.o: ./srcs/init/mutex_init.c | $(BUILD_DIR)
	@$(CC) $(CFLAGS) $(HEADERS) -MD -MP -o $@ -c $<
	@echo -e $(BLUE)$(NAME)$(RESET) compiling: $@

./build/thread_routine.o: ./srcs/routine/thread_routine.c | $(BUILD_DIR)
	@$(CC) $(CFLAGS) $(HEADERS) -MD -MP -o $@ -c $<
	@echo -e $(BLUE)$(NAME)$(RESET) compiling: $@

./build/philo_stop.o: ./srcs/utils/philo_stop.c | $(BUILD_DIR)
	@$(CC) $(CFLAGS) $(HEADERS) -MD -MP -o $@ -c $<
	@echo -e $(BLUE)$(NAME)$(RESET) compiling: $@

./build/print_nbr.o: ./srcs/utils/print_nbr.c | $(BUILD_DIR)
	@$(CC) $(CFLAGS) $(HEADERS) -MD -MP -o $@ -c $<
	@echo -e $(BLUE)$(NAME)$(RESET) compiling: $@

./build/cleanup.o: ./srcs/utils/cleanup.c | $(BUILD_DIR)
	@$(CC) $(CFLAGS) $(HEADERS) -MD -MP -o $@ -c $<
	@echo -e $(BLUE)$(NAME)$(RESET) compiling: $@

./build/delta_utime.o: ./srcs/utils/delta_utime.c | $(BUILD_DIR)
	@$(CC) $(CFLAGS) $(HEADERS) -MD -MP -o $@ -c $<
	@echo -e $(BLUE)$(NAME)$(RESET) compiling: $@

./build/plog.o: ./srcs/utils/plog.c | $(BUILD_DIR)
	@$(CC) $(CFLAGS) $(HEADERS) -MD -MP -o $@ -c $<
	@echo -e $(BLUE)$(NAME)$(RESET) compiling: $@

./build/dsleep.o: ./srcs/utils/dsleep.c | $(BUILD_DIR)
	@$(CC) $(CFLAGS) $(HEADERS) -MD -MP -o $@ -c $<
	@echo -e $(BLUE)$(NAME)$(RESET) compiling: $@

./build/check_death.o: ./srcs/utils/check_death.c | $(BUILD_DIR)
	@$(CC) $(CFLAGS) $(HEADERS) -MD -MP -o $@ -c $<
	@echo -e $(BLUE)$(NAME)$(RESET) compiling: $@

./build/salloc.o: ./srcs/utils/salloc.c | $(BUILD_DIR)
	@$(CC) $(CFLAGS) $(HEADERS) -MD -MP -o $@ -c $<
	@echo -e $(BLUE)$(NAME)$(RESET) compiling: $@

./build/parsing.o: ./srcs/utils/parsing.c | $(BUILD_DIR)
	@$(CC) $(CFLAGS) $(HEADERS) -MD -MP -o $@ -c $<
	@echo -e $(BLUE)$(NAME)$(RESET) compiling: $@

./build/main.o: ./srcs/main.c | $(BUILD_DIR)
	@$(CC) $(CFLAGS) $(HEADERS) -MD -MP -o $@ -c $<
	@echo -e $(BLUE)$(NAME)$(RESET) compiling: $@

./build/simulation.o: ./srcs/simulation.c | $(BUILD_DIR)
	@$(CC) $(CFLAGS) $(HEADERS) -MD -MP -o $@ -c $<
	@echo -e $(BLUE)$(NAME)$(RESET) compiling: $@

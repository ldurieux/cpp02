NAME		= fixed

SRCS		= \

CPPSRCS		= \
			  main.cpp \
			  fixed.cpp \

ASMSRCS		= \

HEADERS		= \
			  .

CCDEFS		= \

SUBPROJECTS	= \

LIB_NAMES	= \
			  
DYN_LIBS	= \

FRAMEWORKS	= \

DYN_LIBS	:= $(addprefix -l, $(DYN_LIBS))
FRAMEWORKS	:= $(addprefix -framework , $(FRAMEWORKS))

LIBS		= $(subst lib,-l,$(notdir $(LIB_NAMES)))
LIB_LD		= $(foreach lib,$(LIB_NAMES),-L$(lib))
LIB_PATHS	= $(foreach lib,$(LIB_NAMES),$(lib)/$(notdir $(lib)).a)
LIB_HEADERS	= $(foreach lib,$(LIB_NAMES),-I$(lib)/includes/)

CCDEFSFLGS	= $(foreach def,$(CCDEFS),-D $(def))

BUILDDIR	= build
OBJS		= $(SRCS:%.c=$(BUILDDIR)/%.o) \
			  $(CPPSRCS:%.cpp=$(BUILDDIR)/%.o) \
			  $(ASMSRCS:%.s=$(BUILDDIR)/%.o)
DEPS		= $(SRCS:%.c=$(BUILDDIR)/%.d) \
			  $(CPPSRCS:%.cpp=$(BUILDDIR)/%.d)
CC			= cc
CCWFLGS		= -Wall -Wextra -Werror
CCDBGFLGS	= -fsanitize=address -g3
CCO1FLGS	= -O1 -march=native
CCO2FLGS	= -O2 -march=nativer
CCO3FLGS	= -O3 -march=native
CXX			= c++ -std=c++98
CXXWFLGS	= -Wall -Wextra -Werror -g3
CXXDBGFLGS	= -fsanitize=address -g3
CXXO1FLGS	= -O1 -march=native
CXXO2FLGS	= -O2 -march=nativer
CXXO3FLGS	= -O3 -march=native
DEPSFLAGS	= -MMD -MP
RM			= rm -Rf
MAKE		= make -C
MKDIR		= mkdir
AR			= ar
ARFLAGS		= rcs
NASM		= nasm
NASMFLAGS	= -felf64

all : libs sub_projects $(NAME)

$(NAME) : $(LIB_PATHS) $(OBJS)
		$(CXX) $(CXXWFLGS) -o $(NAME) $(OBJS) $(LIB_LD) $(LIBS) $(DYN_LIBS) $(FRAMEWORKS)

bonus : $(NAME)

libs :
		$(foreach lib, $(LIB_NAMES), \
			$(MAKE) $(lib); \
		)

sub_projects :
		$(foreach project, $(SUBPROJECTS), \
			$(MAKE) $(project); \
		)

clean :
		-$(RM) $(BUILDDIR)

fclean : clean
		$(foreach project, $(SUBPROJECTS), \
			$(MAKE) $(project) fclean; \
		)
		$(foreach lib, $(LIB_NAMES), \
			$(MAKE) $(lib) fclean; \
		)
		-$(RM) $(NAME)

re : fclean all

-include $(DEPS)

$(BUILDDIR)/%.o : %.c Makefile $(LIB_PATHS)
		@mkdir -p $(@D)
		$(CC) $(CCWFLGS) $(DEPSFLAGS) $(CCDEFSFLGS) -I$(HEADERS) $(LIB_HEADERS) -c $< -o $@

$(BUILDDIR)/%.o : %.cpp Makefile $(LIB_PATHS)
		@mkdir -p $(@D)
		$(CXX) $(CXXWFLGS) $(DEPSFLAGS) $(CCDEFSFLGS) -I$(HEADERS) $(LIB_HEADERS) -c $< -o $@

$(BUILDDIR)/%.o : %.s Makefile $(LIB_PATHS)
		@mkdir -p $(@D)
		$(NASM) $(NASMFLAGS) -o $@ $<

.PHONY: all clean fclean re bonus libs sub_projects

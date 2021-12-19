  &#xa0;

<h1 align="center"> 🍝 Philosophers </h1>

<h2 align="center">I’ve never thought philosophy would be so deadly </h2>
<br>
<p align="center">

  <img alt="Github top language" src="https://img.shields.io/github/languages/top/anolivei/Philosophers42?color=3de069">

  <img alt="Github language count" src="https://img.shields.io/github/languages/count/anolivei/Philosophers42?color=3de069">

  <img alt="Repository size" src="https://img.shields.io/github/repo-size/anolivei/Philosophers42?color=3de069">

  <img alt="Norminette" src="https://github.com/anolivei/Philosophers42/actions/workflows/norminette.yml/badge.svg?event=push">

</p>

<hr>

<p align="center">
  <a href="#about">About</a> &#xa0; | &#xa0; 
  <a href="#links">Links</a> &#xa0; | &#xa0;
  <a href="#functions">Functions</a> &#xa0; | &#xa0;
  <a href="#starting">Starting</a> &#xa0; | &#xa0;
  <a href="https://github.com/anolivei" target="_blank">Author</a>
</p>

<br>

## About ##

-  Philosophers is a project at school 42 and the instructions were given in the [subject](https://github.com/anolivei/Philosophers42/blob/master/subject.pdf).


## Links ##
- [Dining Philosophers Problem 1](https://www.youtube.com/watch?v=NbwbQQB7xNQ)
- [Dining Philosophers Problem 2](https://www.youtube.com/watch?v=trdXKhWAGdg)
- [Notion1](https://www.notion.so/Philosophers-2b872948598e4f0cba91c66d8b5ba821) by [jfreitas](https://github.com/joycemacksuele)
- [Notion2](https://grizzly-muenster-737.notion.site/Philosophers-55c385e0a6224d629c86231821e3ce10) by [lfrasson](https://github.com/laisarena)
- [To understand time 1](https://github.com/laisarena)
- [To understand time 2](https://stackoverflow.com/questions/60932647/gettimeofday-why-use-both-seconds-and-microseconds)
- [Tester](https://github.com/GOAT095/philosophers-tester)
- [Script Maroto xD](https://github.com/GOAT095/philosophers-tester/blob/master/delay_o_meter.py)
- [pthreads Tutorial](https://randu.org/tutorials/threads/)
- [Playlist about C Threads](https://www.youtube.com/watch?v=d9s_d28yJq0&list=PLfqABt5AS4FmuQf70psXrsMLEDQXNkLq2)
- [pthreads Short Introduction](https://www.youtube.com/watch?v=d9s_d28yJq0)
- [How to pass arguments to threads](https://www.youtube.com/watch?v=HDohXvS6UIk)
- [What are detached threads?](https://www.youtube.com/watch?v=-i8Kzuwr4T4)
- [An Application of Pthreads and Mutexes](http://files.kipr.org/gcer/2009/proceedings/Myers_ApplicationPthreads.pdf)
- [Multithreading part 1](https://www.youtube.com/watch?v=GNw3RXr-VJk)
- [Multithreading part 2](https://www.youtube.com/watch?v=sDLQWivf1-I)
- [Miro](https://miro.com/app/board/o9J_l0AjIkc=/) by [lorenuar](https://github.com/lorenuars19)
- [Visualizer](https://nafuka11.github.io/philosophers-visualizer/)
- [Figurinha](https://excalidraw.com/#json=6229317793087488,Xvs-N9yiAj1uWS7JCOepZQ) by [pcunha](https://github.com/PCC19)

## Functions ##

Only the following functions are allowed to be used in this project on mandatory part:<br>
| Function | Description | Function | Description |
|----------|-------------|----------|-------------|
| memset | fill memory with a constant byte | pthread_create | create a new thread |
| printf | format and print data | pthread_detach | detach a thread |
| malloc | allocate dynamic memory | pthread_join | join with a terminated thread |
| free | free dynamic memory | pthread_mutex_init | initialise the mutex |
| write | write to a file descriptor | pthread_mutex_destroy | destroy the mutex object |
| usleep | suspend execution for microsecond intervals | pthread_mutex_lock | lock the mutex object |
| gettimeofday |  get the time and gives the number of seconds and microseconds since the Epoch | pthread_mutex_unlock | releases the mutex object |

## Starting ##

```bash
# Clone this project
git clone https://github.com/anolivei/Philosophers42

# Access
cd Philosophers42/philo/

# Compile the program
make

# To understand args
./philo help

# To run (example)
./philo 10 80 80 80 2

# To remove objects
make clean

# To remove objects and executable
make fclean

```

&#xa0;

<div align="center" id="top"> 
  <img src="./.github/app.gif" alt="Gh_philosophers" />
</div>

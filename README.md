# SCBM-Prolog　A small Prolog implementation

## What is SCBM-Prolog?

SCBM stands for **Sasagawa Continuation Backtracking Model**. It is a method for compiling Prolog based on a different approach from the Warren Abstract Machine (WAM).

SCBM-Prolog compiles Prolog programs directly into C code. Execution is controlled by explicit **success continuations** and **failure continuations**, implemented using C's `goto` mechanism. Success continuations determine where execution proceeds after a goal succeeds, while failure continuations determine where execution resumes during backtracking.

The main goal of SCBM is simplicity. Its execution model is relatively small and direct, making the compiler and runtime easier to implement and understand than a traditional WAM-based system.

At the current stage of development, the primary focus is **correctness of the fundamental execution model**, especially recursion, backtracking, and the interaction between success and failure continuations. Performance optimization and additional features will follow once these basic mechanisms are fully stable.


license is modified BSD.


![scbm](scbm.png)

## SCBM in One Minute

Prolog is based on ideas that are quite different from those of most other programming languages. One of its distinctive features is **backtracking**.

When a predicate is executed and unification succeeds, Prolog proceeds to the next predicate. If it fails, Prolog goes back to a previous predicate and tries another possibility. By repeating this process, Prolog searches for solutions.

Efficiently implementing this control flow—moving forward on success and going back to retry on failure—is one of the challenging parts of implementing Prolog.

SCBM implements this mechanism using two kinds of continuations: a **success continuation** and a **failure continuation**.

When executing a predicate:

* If it succeeds, the **success continuation** specifies where execution should continue.
* If it fails, the **failure continuation** specifies where execution should return to retry another possibility.

The SCBM-Prolog compiler generates these continuations as control flow using C's `goto`.

In short, SCBM implements Prolog backtracking with a simple mechanism based on these two continuations.

That is **SCBM — the Sasagawa Continuation Backtracking Model**.


## Relation to ISO-Prolog
Although SCBM-Prolog is a superset of ARITY/Prolog, it also implements most ISO-Prolog predicates. In addition, by adding the -d option at startup, strings are represented using double quotes, just as in ISO. For study and educational purposes, ISO-Prolog code can be sufficiently reproduced. Please refer to SUPER.md for details.


## Installation
In home directory ,make clone or download zip file from github.
Change to the git cloned or downloaded M-Prolog directory.

- Type "sudo make install".

Update SCBM-Prolog
- Type "sudo make clean".
- Type "sudo make install".

SCBM-Prolog requires ncurses library. Please install ncurses.

```sh
sudo apt install libncurses-dev
```

# Supported OS:

- Raspberry Pi OS
- Ubuntu
- Linux Mint

- Use of other operating systems is at your own discretion.
Unsupported Operating Systems
Operating systems other than the officially supported ones (Raspberry Pi OS, Ubuntu, Mint) are not officially supported, as I do not have the hardware or sufficient experience to properly test them.
If you wish to run this project on an unsupported OS, please feel free to adapt the code on your own.
If your modifications are successful, we encourage you to publish a branch so that others can benefit from your work.


## File Path Resolution in SCBM-Prolog

When loading files, SCBM-Prolog automatically resolves file paths based on the following rules:

1. **Relative paths** (starting with `./` or `../`) are used directly. If no extension is present, `.pl` is appended.
2. If the environment variable `SCBM_HOME` is set, files are loaded from that directory.
3. If `SCBM_HOME` is not set but `HOME` is, files are loaded from `$HOME/scbm/`.
4. Otherwise, the given name is used as-is. If it lacks an extension, `.pl` is appended.

In all cases, if the file name already contains a dot (`.`), it is assumed to include an extension and `.pl` will not be added.


## Uninstall
On Linux type "sudo make uninstall" on terminal.


# invoke
To invoke scbm, enter command from terminal

```
scbm

-c option is for start up file.

e.g.
scbm -c init.pl

-r option is for Not editable REPL mode.
Default, REPL is editable.
```

other option

```
$ scbm -h
List of options:
-a          -- string is ARITY/PROLOG e.g. $abc$.
-c filename -- NPL starts after reading the file.
-f          -- NPL treats undefined errors as fail.
-h          -- display help.
-l          -- display Lisp like S.
-m N        -- NPL runs with N(30>=N>=10) mega cells.
-n          -- NPL runs with network mode.
-r          -- NPL does not use editable REPL.
-s filename -- NPL runs file with script mode.
-v          -- dislplay version number.
```

## Goal
SCBM-Prolog aims to enjoy the experience of DEC10-Prolog from the 1980s.

## Video 
[N-Prolog in 1 minute Tutorials](https://www.youtube.com/watch?v=w51nbR98cA8&list=PLZJFIgVbFOoJoQR0JjDsMcqpR_qiQ7cIU)

## example
```prolog
SCBM-Prolog Ver 1,01
?- length([1,2,3],X).
X = 3
yes


?- X is 2^1000.
X = 107150860718626732094842504906000181056140481170553360744375038837035105112493612249319837881569585812
7594672917553146825187145285692314043598457757469857480393456777482423098542107460506237114187795418215304
6474983581941267398767559165543946077062914571196477686542167660429831652624386837205668069376
yes

?- append(X,Y,[1,2,3]).
X = []
Y = [1,2,3];
X = [1]
Y = [2,3];
X = [1,2]
Y = [3];
X = [1,2,3]
Y = [];
no
?- 
?- ['tests/queens.pl'].
yes
?- test.
....
[9,7,2,4,1,8,5,3,6]
[9,7,3,8,2,5,1,6,4]
[9,7,4,2,8,6,1,3,5]
no
?- 



?- halt.
- good bye -

```

# Editable REPL
key-bindings are as follows:

- → move right
- ← move left 
- ↑ recall history older
- ↓ recall history newer
- return insert end of line
- back-space  backspace
- Esc Tab completion

# unicode
You can use unicode.

```

動物(人間).
人間(ジョー).

動物(X) :- 人間(X).

?- ['tests/animal.pl'].
yes
?- 動物(ジョー).
yes
?- 動物(X).
X = 人間 .
yes

```
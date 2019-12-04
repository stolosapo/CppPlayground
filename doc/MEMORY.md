# Memory Leak Detection

## [Valgrind](http://valgrind.org/)

#### installation
- Download current version
- untar it into `/opt/` folder
- install it:

```bash
./configure
make
sudo make install
```

#### run
```bash
valgrind --tool=memcheck --leak-check=full --show-leak-kinds=all --log-file=valgrind.log ./runner
```
- more args:

```bash
--leak-check=yes
--leak-check=full
--show-leak-kinds=all
--log-file=<filename>
```

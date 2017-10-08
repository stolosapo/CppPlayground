# CppPlayground
[![Build Status](https://travis-ci.org/stolosapo/CppPlayground.svg?branch=master)](https://travis-ci.org/stolosapo/CppPlayground)

A playground for C++ applications and experiments...


### Installation
----------------

```
./initialize.sh
make
```


### Run
-------

```
cd bin
./runner
```


### Run Tests
-------------

```
make clean
./initialize
make tester
cd bin
./tester
```


### Additional Features:
------------------------

#### Icecast client parameter: `WITH_ICECAST`

If you want to use the icecast client you must compile as following. This feature is still under development. Alse this feature prerequisites to have `libshout` library installed on your system.

```
./initialize.sh
make WITH_ICECAST=1
```

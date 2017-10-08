# CppPlayground
[![Build Status](https://travis-ci.org/stolosapo/CppPlayground.svg?branch=master)](https://travis-ci.org/stolosapo/CppPlayground)

A playground for C++ applications and experiments...


### Installation

```
./initialize.sh
make
```


### Run

```
cd bin
./runner
```


### Additional Features:
------------------------

#### Icecast client parameter: `WITH_ICECAST`

If you want to use the icecast client you must compile as following:
This feature is still on deployment.

```
./initialize.sh
make WITH_ICECAST=1
```


### Run Tests

```
make clean
./initialize
make tester
cd bin
./tester
```

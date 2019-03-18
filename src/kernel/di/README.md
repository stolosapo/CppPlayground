# Dependancy Injection

With D.I. feature we can inject any object in any part of the application.

## How to use

### Step 1: Prepare the wanted `service`.

The object that we want to inject has to implement `IService` interface.
The `IService` interface locates in the `src/lib/service/` folder.

Then we must create a factory class that creates a new instance of the 
wanted class. The factory must implement the `IServiceFactory` interface. 
Again this interface locates in `src/lib/service/` folder.

see `ILogService` in `src/log` for example. 
The interface `ILogService` extends `IService`. 
Also the `LogServiceFactory` extends `IServiceFactory`.

### Step 2: Register `service`.

Then we must register the `service` to tha `globalAppContext`.

`globalAppContext` is the context of the whole application. This context
initialized first of everything in the `main` and contains all `services`.

In order to register the wanted service we must add it in the 
`GlobalAppContextRegistration.cpp` file in the `src/lib/di/` folder.

example:
```
void registerServices()
{
	/* Logging Service */
	registerGlobalService<LogServiceFactory>(SINGLETON, "logService", new LogServiceFactory);
}

```

the method `registerGlobalService` is a template method and takes as type 
the factory class of `service` that we want to inject.
as first param takes the `InjectionScope` of the service.
the scopes can be one of: `SINGLETON`, `REQUEST`, `START_UP`.
as second param takes the name of the service. With this name we can 
access again the wanted `service`. 
As thrird param takes a new pointer to the factory that creates 
the wanted service.

### Step 3: Injection

After all these we can inject the wanted `service`.

in the file that we want out `service` we must include `GlobalAppContext.h` 
file that lacated in `src/lib/di`. 
Then we can call the `inject` method.

This method is a template method. As type takes the wanted `service` type.
As parameter takes the name of the wanted `service`, as we register in Step 2.
And returns a pointer the wanted `service`.

example:
```
ILogService logSrv = inject<ILogService>("logService");
```


# `InjectionScope`

There are three injection scopes for the application.

### `SINGLETON`
This means that the first time that a wanted `service` will be injected,
then it will be initialized with the `IServiceFactory`. All the rest
of the times that will be injected the same reference of the `service`
will be returned.

### `REQUEST`
This means that every time that a `service` will be injected,
every time a new instance of this `service` will be created.

### `START_UP`
This means that the `service` will be intantiated on the start up of the 
application and inject method will return the same reference of this `service`.
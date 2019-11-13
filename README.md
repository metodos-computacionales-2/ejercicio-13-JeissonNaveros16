Exercise 2
Aparece el mensaje: "assignment of read-only reference" Lo cual indica que el valor que se pasa por referencias no puede ser cambiado, reasignado, debido a que el método lo toma como constante.

Exercise 4
La diferencia está en el tipo de parámetros que recibe cada una y dependiendo de estos C++ sabe a cual llamar.

Exercise 5
El error que se presenta es de segmentation fault (core dumped), esto se debe a que no hay tanto espacio para reservarlo a un array temporal. Por otro lado, cuando se implementa en el Heap, no se lanza el mismo error. De esto se puede concluir que asginar y modificar variables a traves de sus referencias es más útil, pero requiere mayor atención.
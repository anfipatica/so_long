# SO_LONG

## RESUMEN:
Este proyecto consiste en crear un pequeño y sencillo juego 2D.
- Tienes un punto de partida, un punto de salida y coleccionables para desbloquear la salida. Lo demás es cosa tuya.

<br>
<img width="800" alt="bonus detail clip" src="https://media.giphy.com/media/uf2GYmN1aTcPMJ2Vnm/giphy.gif">
Realicé una serie de bonus con los que conseguí el 125%. Esos bonus incluyen:
<br>

> -  [x] Pequeña animación del personaje y los coleccionable.
> -  [x] Mostrar por pantalla el número de movimientos.
> -  [x] Añadir una cartela informativa del funcionamiento e *historia*.
> -  [x] Añadir cartela cuando el jugador gana o pierde.
> -  [x] Mayor complejidad gráfica de los muros: Muro interconectado en vez de un único sprite repetido.
> -    Esto implicó la creación de 17 sprites única y exclusivamente para los muros, y aún podrían añadirse unos cuantos más para mejor resultado en ciertos casos.
> - [x] Lo más importante: Adición de enemigos con movimiento.

En este README sólo pondré el resultado del juego y algún comentario de cosas que me gustaría destacar, a continuación adjunto

[mis apuntes en notion](https://www.notion.so/SO-LONG-90b8e0195b49431e8a672b1240d933aa?pvs=4)
por si alguien quiere mirarlos y tener un mayor entendimiento del programa y su creación.

<br>

## Clips del bonus

<img width="700" alt="bonus clip 1, zoomed" src="https://media.giphy.com/media/OfswESe6rdhSHHfXwd/giphy.gif">
<br>
<img width="700" alt="bonus clip 2" src="https://media.giphy.com/media/uTqMtzW4nVZckzuUj6/giphy.gif">
<br>

## Clips del juego base

<img width="700" alt="non bonus clip" src="https://media.giphy.com/media/6UYH5gkm3Ezp3RidV7/giphy.gif">


## Algunos comentarios:
El proyecto se hizo al mes de realizar el cambio a Linux en Madrid, por tanto aún no se había establecido si se permitía el uso de
la mlx de Codam, que tiene algunas funcionalidades extras y, sobretodo, permite trabajar sin problemas las imágenes con transparencia en
Linux, y es que la mlx en Linux no permite superponer imágenes con transparencia.

Por no quedarme quieta esperando al aviso (que llegó 2 semanas después de que entregara el proyecto) busqué información de cómo sortear este problema.
Había dos opciones: 
- Crear imágenes sin transparencias
- complicarte la vida y crear funciones que comparen las dos imágenes a superponer (Por ejemplo, el suelo y el personaje) y pinten pixel a pixel.

¿Cómo funciona esto? Yo vi [este blog, Pulgamecanica](https://pulgamecanica.herokuapp.com/posts/mlx-transparency) que lo explica muy bien.
También me fue muy útil haber visto previamente [el video de Oceano](https://www.youtube.com/watch?v=9eAPbNUQD1Y) en que creamos un programa que "pinta" un cuadro de Pollock, ya que te enseña a crear tu propia versión de mlx_pixel_put(), la función que permite pintar pixel a pixel pero que está prohibida usar.

Muy resumidamente: Conocemos el tamaño que tienen las imágenes. Leemos cada pixel de la imagen a superponer (el personaje). Detectamos el color del pixel, si hay color, pintamos el pixel correspondiente de la pantalla de ese color. Es decir, el mapa es una matriz. El personaje se encuentra en una posición concreta de esa matriz, pero la imagen del personaje es otra matriz, y el pixel que estamos leyendo tiene su propia posición en esta. Un lío de coordenadas vamos.

Si no se detecta color ya que ese pixel concreto es transparente, realizamos el mismo proceso pero con la imagen de debajo, el suelo.

## Movimiento de los enemigos
La mayoría de este proyecto lo realicé en casa, por lo que no contrasté las ideas con los compañeros tanto como me habría gustado. Sabía que una parte del bonus era añadir enemigos, y para mí era obvio que los enemigos se debían mover, así que eso empecé a implementar. Luego descubrí que la mayoría de la gente hacía enemigos estáticos, pero ya llevaba más de un día implementando (fallidamente) el movimiento, así que iba a seguir con ello.

Y es que lo difícil no es el movimiento como tal, hacer que un enemigo se mueva es fácil, lo difícil es lidiar con **las colisiones entre enemigos**.

Tras mucho rebanarme la cabeza, opté por este planteamiento:
- Los enemigos sólo se moverían de izquierda a derecha, en una misma dirección hasta colisionar.
- Primero se establece el movimiento de cada enemigo. En este momento hay 4 opciones:
  1. Si el enemigo o bloque de enemigos se encuentran entre bloques permanentes (muros o la salida), establecen su movimiento a **permanentemente estáticos**, nunca podrán moverse.
  2. Si el enemigo o bloque de enemigos se encuentran entre uno o más bloques no permanentes (los coleccionables), se mantendrán como **estáticos** hasta que el bloque no permanente desaparezca (cojas el coleccionable), creando espacio para moverse.
3.   Si el enemigo tiene su derecha despejada, siempre empezará el movimiento **a su derecha**.
4.   Si la derecha no está despejada, empezará el movimiento **a su izquierda**

- La prioridad de movimiento es por orden de lectura de la matriz, es decir, de arriba a abajo, de derecha a izquierda.
- De producirse colisión, el enemigo emplea un turno de movimiento en cambiar su dirección, turno en que está estático.

<img width="700" alt="foe movement clip" src="https://media.giphy.com/media/DXnQhYGb8K8PABGe6i/giphy.gif">

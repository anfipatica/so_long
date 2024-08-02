# SO_LONG

## RESUMEN:
Este proyecto consiste en crear un pequeño y sencillo juego 2D.
- Tienes un punto de partida, un punto de salida y coleccionables para desbloquear la salida. Lo demás es cosa tuya.


<br>
En este README sólo pondré el resultado del juego, a continuación adjunto

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





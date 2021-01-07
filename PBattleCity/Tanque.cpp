#include "Tanque.h"
#include "Bala.h"
#include <map>
#include <vector>

Tanque::Tanque()
{
	tipoActor = TipoActor_Tanque;
	ancho = tamanoTanque;
	alto = tamanoTanque;
	velocidad = 0;
	fuegoTiempoEnfriamiento = 0.0;

	//setColor(ColorConsola_GrisOscuro, ColorConsola_Gris);
	//setImagen(ColorConsola_Verde, ColorConsola_Gris);
}

void Tanque::actualizar(float _dt)
{
	Actor::actualizar(_dt);

	if (fuegoTiempoEnfriamiento > 0)
		fuegoTiempoEnfriamiento -= _dt;
}

void Tanque::renderizar(SistemaRenderizacion* _sistemaRenderizacion)
{
	Actor::renderizar(_sistemaRenderizacion);

	/*int fila = int(y);
	int columna = int(x);

	for (int f = 0; f < tamanoTanque; f++) {
		for (int c = 0; c < tamanoTanque; c++){
			DatosSimboloConsola sd = imagenTanque[direccion][f][c];
			_sistemaRenderizacion->dibujarCaracter(fila + f, columna + c, sd.simbolo, sd.colorSimbolo, sd.colorFondo);
		}
	}*/
}

void Tanque::setImagen(ColorConsola _colorSimbolo, ColorConsola _colorFondo)
{
	vector<DatosSimboloConsola> vAvatarIzquierda{
		DatosSimboloConsola{(char)220, _colorSimbolo, _colorFondo },
		DatosSimboloConsola{(char)220, _colorSimbolo, _colorFondo },
		DatosSimboloConsola{(char)220, _colorSimbolo, _colorFondo },
		DatosSimboloConsola{(char)13, _colorSimbolo, _colorFondo },
		DatosSimboloConsola{(char)196, _colorSimbolo, _colorFondo },
		DatosSimboloConsola{(char)4, ColorConsola_Violeta, _colorFondo },
		DatosSimboloConsola{(char)221, _colorSimbolo, _colorFondo },
		DatosSimboloConsola{(char)13, _colorSimbolo, _colorFondo },
		DatosSimboloConsola{(char)223, _colorSimbolo, _colorFondo },
		DatosSimboloConsola{(char)223, _colorSimbolo, _colorFondo },
		DatosSimboloConsola{(char)223, _colorSimbolo, _colorFondo }
	};

	vector<DatosSimboloConsola> vAvatarDerecha{
		DatosSimboloConsola{(char)220, _colorSimbolo, _colorFondo },
		DatosSimboloConsola{(char)220, _colorSimbolo, _colorFondo },
		DatosSimboloConsola{(char)220, _colorSimbolo, _colorFondo },
		DatosSimboloConsola{(char)13, _colorSimbolo, _colorFondo },
		DatosSimboloConsola{(char)221, _colorSimbolo, _colorFondo },
		DatosSimboloConsola{(char)4, ColorConsola_Violeta, _colorFondo },
		DatosSimboloConsola{(char)196, _colorSimbolo, _colorFondo },
		DatosSimboloConsola{(char)13, _colorSimbolo, _colorFondo },
		DatosSimboloConsola{(char)223, _colorSimbolo, _colorFondo },
		DatosSimboloConsola{(char)223, _colorSimbolo, _colorFondo },
		DatosSimboloConsola{(char)223, _colorSimbolo, _colorFondo }
	};

	vector<DatosSimboloConsola> vAvatarArriba{
		DatosSimboloConsola{(char)220, _colorSimbolo, _colorFondo },
		DatosSimboloConsola{(char)179, _colorSimbolo, _colorFondo },
		DatosSimboloConsola{(char)220, _colorSimbolo, _colorFondo },
		DatosSimboloConsola{(char)13, _colorSimbolo, _colorFondo },
		DatosSimboloConsola{(char)219, _colorSimbolo, _colorFondo },
		DatosSimboloConsola{(char)4, ColorConsola_Violeta, _colorFondo },
		DatosSimboloConsola{(char)219, _colorSimbolo, _colorFondo },
		DatosSimboloConsola{(char)13, _colorSimbolo, _colorFondo },
		DatosSimboloConsola{(char)223, _colorSimbolo, _colorFondo },
		DatosSimboloConsola{(char)0, _colorSimbolo, _colorFondo },
		DatosSimboloConsola{(char)223, _colorSimbolo, _colorFondo }
	};

	vector<DatosSimboloConsola> vAvatarAbajo{
		DatosSimboloConsola{(char)220, _colorSimbolo, _colorFondo },
		DatosSimboloConsola{(char)0, _colorSimbolo, _colorFondo },
		DatosSimboloConsola{(char)220, _colorSimbolo, _colorFondo },
		DatosSimboloConsola{(char)13, _colorSimbolo, _colorFondo },
		DatosSimboloConsola{(char)219, _colorSimbolo, _colorFondo },
		DatosSimboloConsola{(char)4, ColorConsola_Violeta, _colorFondo },
		DatosSimboloConsola{(char)219, _colorSimbolo, _colorFondo },
		DatosSimboloConsola{(char)13, _colorSimbolo, _colorFondo },
		DatosSimboloConsola{(char)223, _colorSimbolo, _colorFondo },
		DatosSimboloConsola{(char)179, _colorSimbolo, _colorFondo },
		DatosSimboloConsola{(char)223, _colorSimbolo, _colorFondo }
	};

	map<int, DatosSimboloConsola> mAvatarIzquierda;
	map<int, DatosSimboloConsola> mAvatarDerecha;
	map<int, DatosSimboloConsola> mAvatarArriba;
	map<int, DatosSimboloConsola> mAvatarAbajo;
	
	pair<int, DatosSimboloConsola> pAvatarDireccion;
	
	for (int i = 0; i < vAvatarIzquierda.size(); i++) {
		pAvatarDireccion.first = i;
		
		pAvatarDireccion.second = vAvatarIzquierda[i];
		mAvatarIzquierda.insert(pAvatarDireccion);

		pAvatarDireccion.second = vAvatarDerecha[i];
		mAvatarDerecha.insert(pAvatarDireccion);

		pAvatarDireccion.second = vAvatarArriba[i];
		mAvatarArriba.insert(pAvatarDireccion);

		pAvatarDireccion.second = vAvatarAbajo[i];
		mAvatarAbajo.insert(pAvatarDireccion);
	}


	pair<Direccion, map<int, DatosSimboloConsola>> pAvatar;
	pAvatar.first = Direccion_Izquierda;
	pAvatar.second = mAvatarIzquierda;
	avatar.insert(pAvatar);
	pAvatar.first = Direccion_Derecha;
	pAvatar.second = mAvatarDerecha;
	avatar.insert(pAvatar);
	pAvatar.first = Direccion_Arriba;
	pAvatar.second = mAvatarArriba;
	avatar.insert(pAvatar);
	pAvatar.first = Direccion_Abajo;
	pAvatar.second = mAvatarAbajo;
	avatar.insert(pAvatar);
}

void Tanque::mover(Direccion _direccion)
{
	setDireccion(_direccion);

	setXVelocidad(0);
	setYVelocidad(0);

	switch (direccion)
	{
	case Direccion_Izquierda: setXVelocidad(-velocidad); break;
	case Direccion_Derecha: setXVelocidad(velocidad); break;
	case Direccion_Arriba: setYVelocidad(-velocidad); break;
	case Direccion_Abajo: setYVelocidad(velocidad); break;
	}
}

void Tanque::disparar()
{
	if (fuegoTiempoEnfriamiento > 0)
		return;

	fuegoTiempoEnfriamiento = fuegoTiempoEnfriamientoTanque;

	float x = 0.0;
	float y = 0.0;
	float xVelocidad = 0.0;
	float yVelocidad = 0.0;

	calcularPosicionCeldaFrontal(&x, &y);

	switch (direccion)
	{
	case Direccion_Izquierda: xVelocidad = -velocidadBala; break;
	case Direccion_Derecha: xVelocidad = velocidadBala; break;
	case Direccion_Arriba: yVelocidad = -velocidadBala; break;
	case Direccion_Abajo: yVelocidad = velocidadBala; break;
	}

	Bala* bala = gameManager->crearActor<Bala>(x, y);
	if (bala)
	{
		bala->setTipoActorPropietario(tipoActor);
		bala->setXVelocidad(xVelocidad);
		bala->setYVelocidad(yVelocidad);
	}
}

void Tanque::calcularPosicionCeldaFrontal(float* _x, float* _y)
{
	switch (direccion)
	{
	case Direccion_Izquierda:
		(*_x) = int(getX()) - 0.01;
		(*_y) = int(getY()) + (getAlto() / 2.0);

		break;
	case Direccion_Derecha:
		(*_x) = int(getX()) + getAncho() + 0.01;
		(*_y) = int(getY()) + (getAlto() / 2.0);
		break;
	case Direccion_Arriba:
		(*_y) = int(getY()) - 0.01;
		(*_x) = int(getX()) + (getAncho() / 2.0);
		break;
	case Direccion_Abajo:
		(*_y) = int(getY()) + getAlto() + 0.01;
		(*_x) = int(getX()) + (getAncho() / 2.0);
		break;
	}
}

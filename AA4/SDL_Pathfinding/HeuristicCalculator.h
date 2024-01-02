#pragma once
#include "Vector2D.h"
#include "EuclideanDistance.h"
#include "ManhattanDistance.h"
#include "ChebyshevDistance.h"
#include "DiagonalDistance.h"
#include "OctileDistance.h"

#include <map>

#define HC HeuristicCalculator::GetInstance()

class HeuristicCalculator
{
private:
	static HeuristicCalculator* instance;
	std::map<std::string, HeuristicFunction*> heuristicFunctions;
	std::string currentFunctionKey;
	float d_param;

	const std::string EUCLIDEAN_KEY = "Euclidean";
	const std::string MANHATTAN_KEY = "Manhattan";
	const std::string CHEBYSHEV_KEY = "Chebyshev";
	const std::string DIAGONAL_KEY = "Diagonal";
	const std::string OCTILE_KEY = "Octile";

	HeuristicCalculator();

public:
	static HeuristicCalculator* GetInstance();

	float CalculateHeuristic(Vector2D point, Vector2D goal);

	void SetFunctionToEuclidean();
	void SetFunctionToManhattan();
	void SetFunctionToChebyshev();
	void SetFunctionToDiagonal();
	void SetFunctionToOctile();
	void SetDParam(float _d_param) { d_param = _d_param; }

	//Podem resoldre el problema de les diferents funcions utilitzant un enum class HeuristicFunction i preguntant pel
	//tipus a la funció CalculateHeuristic, per executar una d'aquestes tres funcions:
		//CalculateEuclideanDistance()
		//CalculateManhattanDistane()
		//CalculateChebyshevDistance()

	//Però això incompleix SOLID.
	//Per evitar preguntar per tipus, caldria fer una classe abstracta "HeuristicFunction" de què heredarien
	//Euclidean, Manhattan, Chebyshev... 
	//Se li passaria un objecte HeuristicFunction* heuristicFunction, i faria: heuristicFunction->CalculateHeuristic
	//Tanmateix, això implicaria construir un objecte cada cop que volguéssim calcular una heurística
	//Cosa molt absurda, quan sols volem cridar a una funció

	//Tot i infringir SOLID, utilitzar un enum class ens facilita actualitzar l'heuristicFunction en runtime
	//Simplement cal actualitzar una variable
	//Si tenim l'estructura de classes, és més complicat -> fer casts
	//Utilitzant herència, igualment hauríem de tenir una variable que indiqués quina heurística estem emprant
	//Aquesta variable hauria d'estar al singleton HeuristicCalculator

	//En ser HeuristicCalculator un Singleton, podríem tenir les següents funcions:
		//SetFunctionToEuclidean()
		//SetFunctionToManhattan()
		//SetFunctionToChebyshev()
	//El jugador, en el moment d'executar l'algorisme i només en aquell moment, decidiria quina funció heurística vol
	//És en aquest moment quan es cridarien les 3 funcions de dalt

	//Això el que faria és un cast del nostre objecte function a la classe filla desitjada
	//Llavors, en cridar CalculateHeuristic, es podria fer heuristicFunction->Calculate()
};
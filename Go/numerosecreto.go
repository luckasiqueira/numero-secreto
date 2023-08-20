package main

import (
	"fmt"
	"math"
	"math/rand"
)

var chute int
var numeroSecreto int = rand.Intn(100 + 1)

var tentativas = 0
var rodada = 1
var pontos float64 = 1000

func main() {
	banner()
	analisa()
}

func banner() {
	fmt.Print("******************************************\n")
	fmt.Print("**** Bem Vindo ao jogo de advinhação! ****\n")
	fmt.Print("******************************************")
	fmt.Print("\n")
	fmt.Print("\nEscolha a dificuldade do jogo:")
	fmt.Print("\n1- Fácil (20 chances) \n2- Médio (10 chances) \n3-Difícil (6 chances)\n")
	fmt.Scan(&tentativas)

	switch tentativas {
	case 1:
		tentativas = 20
	case 2:
		tentativas = 10
	default:
		tentativas = 6
	}
}

func analisa() {
	var chances = tentativas
	var pontosPerdidos float64
	for tentativas > 0 {
		fmt.Print("\nRodada ", rodada, " de ", chances)
		fmt.Print("\nDê seu palpite: ")
		fmt.Scan(&chute)

		acertou := chute == numeroSecreto
		maior := chute > numeroSecreto
		menor := chute < numeroSecreto
		pontosPerdidos = math.Abs(float64(chute - numeroSecreto))
		pontos = pontos - pontosPerdidos

		if acertou {
			fmt.Print("\nParabéns! Você acertou!")
			break
		} else if menor {
			fmt.Print("Seu palpite foi menor que o número secreto!\n")
			tentativas--
			rodada++
			continue
		} else if maior {
			fmt.Print("Seu palpite foi maior que o número secreto!\n")
			tentativas--
			rodada++
			continue
		}
	}
	fmt.Print("\nVocê fez: ", pontos, " pontos.")
	fmt.Print("\nFim do jogo!")
}

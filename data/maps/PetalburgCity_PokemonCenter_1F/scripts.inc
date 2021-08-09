.set LOCALID_NURSE, 1

PetalburgCity_PokemonCenter_1F_MapScripts:: @ 82079E8
	map_script MAP_SCRIPT_ON_TRANSITION, PetalburgCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

PetalburgCity_PokemonCenter_1F_OnTransition: @ 82079F3
	setrespawn HEAL_LOCATION_PETALBURG_CITY
	call Common_EventScript_UpdateBrineyLocation
	end

PetalburgCity_PokemonCenter_1F_EventScript_Nurse:: @ 82079FC
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

PetalburgCity_PokemonCenter_1F_EventScript_FatMan:: @ 8207A0A
	lock
	msgbox PetalburgCity_PokemonCenter_1F_Text_PCStorageSystem, MSGBOX_DEFAULT
	closemessage
	applymovement 3, fdgentiluomo1
	random 4
	switch VAR_RESULT
	case 0, Script_RandomOption1tail
	case 1, Script_RandomOption2tail
	case 2, Script_RandomOption3tail
	case 3, Script_RandomOption4tail
	end

Script_RandomOption1tail::
msgbox illtellyouatail1 MSGBOX_YESNO
closemessage
compare VAR_RESULT, NO
goto_if_eq EventScript_ignorant
msgbox kantolegend MSGBOX_DEFAULT
closemessage
applymovement 3, fdgentiluomo2
waitmovement 0
release
end

Script_RandomOption2tail::
msgbox illtellyouatail2 MSGBOX_YESNO
closemessage
compare VAR_RESULT, NO
goto_if_eq EventScript_ignorant
msgbox jotholegend MSGBOX_DEFAULT
closemessage
applymovement 3, fdgentiluomo2
waitmovement 0
release
end

Script_RandomOption3tail::
msgbox illtellyouatail3 MSGBOX_YESNO
closemessage
compare VAR_RESULT, NO
goto_if_eq EventScript_ignorant
msgbox hoennlegend MSGBOX_DEFAULT
closemessage
msgbox hoennlegend2 MSGBOX_DEFAULT
closemessage
applymovement 3, fdgentiluomo2
waitmovement 0
release
end

Script_RandomOption4tail::
msgbox illtellyouatail4 MSGBOX_YESNO
closemessage
compare VAR_RESULT, NO
goto_if_eq EventScript_ignorant
msgbox sinnohlegend MSGBOX_DEFAULT
closemessage
applymovement 3, fdgentiluomo2
waitmovement 0
release
end

kantolegend:
.string "5 Luglio. Guyana, Sudamerica.\n"
.string "È stato scoperto un nuovo Pokémon\l"
.string "nel cuore della giungla.\p"
.string "10 Luglio. Abbiamo chiamato Mew\n"
.string "il Pokémon appena scoperto.\p"
.string "6 Febbraio. Mew ha dato alla\n"
.string "luce un nuovo Pokémon.\l"
.string "Abbiamo chiamato Mewtwo il\l"
.string "piccolo.\p"
.string "10 Settembre. Mewtwo è davvero\n"
.string "potente.\l"
.string "Non riusciamo a contenere i suoi\l"
.string "istinti feroci.\p"
.string "Mewtwo è il risultato di una\n"
.string "clonazione perfetta del DNA di Mew\l"
.string "le sembra essere persino più forte\l"
.string "di quest'ultimo. Si dice inoltre\l"
.string "che Mewtwo, essendo un Pokémon\l"
.string "artificiale sia più forte di tutti\l"
.string "gli altri, eccetto per uno solo.$"

jotholegend:
.string "Un giorno, in epoche di guerre, la\n"
.string "Torre di Latta, divenne la Torre\l"
.string "Bruciata a causa di un incendio.\l"
.string "Tre Pokémon di cui nessuno sapeva\l"
.string "il nome, salvarono tutti gli altri\l"
.string "ma sfortunatamente, lì, persero la\l"
.string "vita. Quando le fiamme si\l"
.string "spensero, nel cielo, comparve una\l"
.string "luce dai colori dell'arcobaleno.\l"
.string "E' lì che  sopraggiunse il\l"
.string "Pokémon Ho-oh, che con il suo\l"
.string "potere resuscitò i Pokémon,\l"
.string "chiamati successivamente, Suicune,\l"
.string "Entei e Raikou. La gente, cacciò\l"
.string "però quei Pokémon, spaventati dal\l"
.string "loro potere, invece che dargli\l"
.string "onore.$"

hoennlegend:
.string "In un'epoca antichissima, quando\n"
.string "il pianeta era ancora giovane, il\l"
.string "mondo traboccava di una\l"
.string "straordinaria energia naturale,\l"
.string "da cui i Pokémon leggendari\l"
.string "traevano il loro incredibile\l"
.string "potere. Sempre avidi di questa\l"
.string "energia, Groudon e Kyogre si\l"
.string "scontravano continuamente,\l"
.string "mettendo in pericolo l'esistenza\l"
.string "degli esseri umani e dei Pokémon\l"
.string "di Hoenn. In epoche successive,\l"
.string "la trasformazione, causata\l"
.string "dall'assorbimento dell'energia\l"
.string "del pianeta, fu chiamata\l"
.string "archeorisveglio, da cui i nomi\l"
.string "ArcheoGroudon e ArcheoKyogre.$"

hoennlegend2:
.string "Dalle vertiginose altezze in cui\n"
.string "risiedeva, un Pokémon assisteva\l"
.string "alla furibonda battaglia che\l"
.string "infuriava sul pianeta. Era il\l"
.string "Pokémon che danza nei cieli:\l"
.string "Rayquaza. Dopo venti giorni gli\l"
.string "esseri umani, stremati, levarono\l"
.string "un'invocazione di aiuto a\l"
.string "Rayquaza, davanti a una\l"
.string "pietra che brillava dei colori\l"
.string "dell'arcobaleno. Rayquaza si\l"
.string "trasformò in MegaRayquaza e mise\l"
.string "pace allo scontro epico.$"

sinnohlegend:
.string "In principio era il caos, un\n"
.string "tumulto agitato di caos.\l"
.string "Nel centro del caos, quando tutto\l"
.string "divenne una cosa sola, comparve\l"
.string "un Uovo.\l"
.string "Caduto dal vortice, l'Uovo diede\l"
.string "vita alla Creatura Originaria.\l"
.string "Dalla Creatura Originaria vennero\l"
.string "generati due esseri.\l"
.string "Il tempo cominciò a scorrere. Lo\l"
.string "spazio cominciò a espandersi.\l"
.string "Dalla Creatura Originaria vennero\l"
.string "generate tre forme di vita.\l"
.string "I due esseri espressero un\l"
.string "desiderio e da loro nacque la\l"
.string "materia.\l"
.string "Le tre forme di vita espressero\l"
.string "un desiderio e da loro nacque lo\l"
.string "spirito.\l"
.string "Dopo la creazione, la Creatura\l"
.string "Originaria cadde nel sonno\l"
.string "profondo...\p"
.string "Si dice che Sinnoh fu la prima\n"
.string "Regione a nascere. La Creatura\l"
.string "Originaria è Arceus, il Pokémon\l"
.string "Divino. Le tre forme di vita sono\l"
.string "Giratina, Dialga e Palkia.\l"
.string "Giratina fu bandito nel Mondo\l"
.string "Distorto, essendo molto violento.$"

EventScript_ignorant::
msgbox donotdisturbmethenignorant MSGBOX_DEFAULT
applymovement 3, fdgentiluomo2
waitmovement 0
releaseall
end

donotdisturbmethenignorant:
.string "I giovani di oggi non sono più\n"
.string "curiosi come quelli di un tempo.$"

illtellyouatail1:
.string "Sono un grande appassionato di\n"
.string "libri. Ho studiato le più grandi\l"
.string "leggende. Sembri molto giovane,\l"
.string "vuoi per caso che ti racconti la\l"
.string "leggenda della nascita di Mewtwo?$"

illtellyouatail2:
.string "Sono un grande appassionato di\n"
.string "libri. Ho studiato le più grandi\l"
.string "leggende. Sembri molto giovane,\l"
.string "vuoi per caso che ti racconti la\l"
.string "leggenda del famoso incendio di\l"
.string "Amarantopoli, nella vecchia Jotho?$"

illtellyouatail3:
.string "Sono un grande appassionato di\n"
.string "libri. Ho studiato le più grandi\l"
.string "leggende. Sembri molto giovane,\l"
.string "vuoi per caso che ti racconti la\l"
.string "leggenda del Trio Meteo di Hoenn?$"

illtellyouatail4:
.string "Sono un grande appassionato di\n"
.string "libri. Ho studiato le più grandi\l"
.string "leggende. Sembri molto giovane,\l"
.string "vuoi per caso che ti racconti la\l"
.string "leggenda della Creazione a Sinnoh?$"

fdgentiluomo1:
face_down
step_end

fdgentiluomo2:
face_up
step_end

PetalburgCity_PokemonCenter_1F_EventScript_Youngster:: @ 8207A13
	msgbox PetalburgCity_PokemonCenter_1F_Text_OranBerryRegainedHP, MSGBOX_NPC
	end

PetalburgCity_PokemonCenter_1F_EventScript_Woman:: @ 8207A1C
	lock
	faceplayer
	msgbox PetalburgCity_PokemonCenter_1F_Text_ManyTypesOfPokemon, MSGBOX_DEFAULT
	specialvar VAR_RESULT, IsStarterInParty
	compare VAR_RESULT, TRUE
	goto_if_eq PetalburgCity_PokemonCenter_1F_EventScript_SayStarterTypeInfo
	release
	end

PetalburgCity_PokemonCenter_1F_EventScript_SayStarterTypeInfo:: @ 8207A38
	compare VAR_STARTER_MON, 0
	call_if_eq PetalburgCity_PokemonCenter_1F_EventScript_SayTreeckoType
	compare VAR_STARTER_MON, 1
	call_if_eq PetalburgCity_PokemonCenter_1F_EventScript_SayTorchicType
	compare VAR_STARTER_MON, 2
	call_if_eq PetalburgCity_PokemonCenter_1F_EventScript_SayMudkipType
	release
	end

PetalburgCity_PokemonCenter_1F_Text_PCStorageSystem: @ 8207A76
	.string "Che interessante collezione di\n"
	.string "libri..$"

PetalburgCity_PokemonCenter_1F_Text_OranBerryRegainedHP: @ 8207AD6
	.string "Stimo molto il Prof.Sherman! Sai\n"
	.string "che il suo Laboratorio si trova\l"
	.string "qui a Mascar?$"

	

PetalburgCity_PokemonCenter_1F_EventScript_SayTreeckoType:: @ 8207A5B
	msgbox PetalburgCity_PokemonCenter_1F_Text_TreeckoIsGrassType, MSGBOX_DEFAULT
	return

PetalburgCity_PokemonCenter_1F_EventScript_SayTorchicType:: @ 8207A64
	msgbox PetalburgCity_PokemonCenter_1F_Text_TorchicIsFireType, MSGBOX_DEFAULT
	return

PetalburgCity_PokemonCenter_1F_EventScript_SayMudkipType:: @ 8207A6D
	msgbox PetalburgCity_PokemonCenter_1F_Text_MudkipIsWaterType, MSGBOX_DEFAULT
	return

	PetalburgCity_PokemonCenter_1F_Text_ManyTypesOfPokemon: @ 8207B09
	.string "There are many types of POKéMON.\p"
	.string "All types have their strengths and\n"
	.string "weaknesses against other types.\p"
	.string "Depending on the types of POKéMON,\n"
	.string "a battle could be easy or hard.$"

PetalburgCity_PokemonCenter_1F_Text_TreeckoIsGrassType: @ 8207BB0
	.string "For example, your TREECKO\n"
	.string "is a GRASS type.\p"
	.string "It's strong against the WATER and\n"
	.string "GROUND types.\p"
	.string "But, it's weak against FIRE-type\n"
	.string "POKéMON.$"

PetalburgCity_PokemonCenter_1F_Text_TorchicIsFireType: @ 8207C35
	.string "For example, your TORCHIC\n"
	.string "is a FIRE type.\p"
	.string "It's strong against the GRASS and\n"
	.string "BUG types.\p"
	.string "But, it's weak against WATER-type\n"
	.string "POKéMON.$"

PetalburgCity_PokemonCenter_1F_Text_MudkipIsWaterType: @ 8207CB7
	.string "For example, your MUDKIP\n"
	.string "is a WATER type.\p"
	.string "It's strong against the FIRE type.\p"
	.string "But, it's weak against GRASS-type\n"
	.string "and ELECTRIC-type POKéMON.$"

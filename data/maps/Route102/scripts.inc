Route102_MapScripts:: @ 81EC0E0
	.byte 0

Route102_EventScript_LittleBoy:: @ 81EC0E1
	msgbox Route102_Text_ImNotVeryTall, MSGBOX_NPC
	end

Route102_EventScript_RouteSignOldale:: @ 81EC0EA
	msgbox Route102_Text_RouteSignOldale, MSGBOX_SIGN
	end

Route102_EventScript_RouteSignPetalburg:: @ 81EC0F3
	msgbox Route102_Text_RouteSignPetalburg, MSGBOX_SIGN
	end

Percorso3_EventScript_RivalTilesopra::
compare VAR_UNUSED_0x4091, 0
goto_if_gt EventScript_finish
playbgm MUS_RG_ENCOUNTER_RIVAL, TRUE
addobject 7
setobjectxy 7, 46 10
setobjectmovementtype 7, MOVEMENT_TYPE_FACE_LEFT
msgbox Text_rival1, MSGBOX_DEFAULT
closemessage
applymovement OBJ_EVENT_ID_PLAYER, move_interrogativo
waitmovement 0
applymovement OBJ_EVENT_ID_PLAYER move_faceright
waitmovement 0
applymovement 7, move_rival
waitmovement 0
msgbox Text_rival2, MSGBOX_DEFAULT
closemessage
trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_103_MUDKIP, Percorso3_Text_RivalDefeat
msgbox Text_rival3, MSGBOX_DEFAULT
addobject 8
setobjectxy 8, 46 11
setobjectmovementtype 8, MOVEMENT_TYPE_FACE_RIGHT
msgbox Text_Gile, MSGBOX_DEFAULT
closemessage
applymovement 7, move_interrogativo
applymovement OBJ_EVENT_ID_PLAYER, move_interrogativo
waitmovement 0
applymovement 7, move_faceright
applymovement OBJ_EVENT_ID_PLAYER, move_faceright
waitmovement 0
applymovement OBJ_EVENT_ID_PLAYER, move_playerafterfight
waitmovement 0
applymovement 8, move_rivaltia
waitmovement 0
msgbox Text_tia2 MSGBOX_DEFAULT
closemessage
applymovement 7, move_interrogativo
applymovement OBJ_EVENT_ID_PLAYER, move_interrogativo
waitmovement 0
msgbox Text_tia3 MSGBOX_DEFAULT
closemessage
applymovement 7, move_interrogativo
applymovement OBJ_EVENT_ID_PLAYER, move_interrogativo
waitmovement 0
msgbox Text_tia4 MSGBOX_DEFAULT
closemessage
msgbox Text_Rivalvstia MSGBOX_DEFAULT
closemessage
applymovement 7, move_facedown
applymovement OBJ_EVENT_ID_PLAYER, move_faceup
waitmovement 0
msgbox Text_final MSGBOX_DEFAULT
closemessage
applymovement 7, move_rivalending
applymovement OBJ_EVENT_ID_PLAYER, move_faceleft
waitmovement 0
applymovement 8, move_sususxsx
waitmovement 0
removeobject 7
applymovement 8, move_facedown
applymovement OBJ_EVENT_ID_PLAYER, move_faceup
waitmovement 0
msgbox Text_finalchat MSGBOX_DEFAULT
closemessage
playfanfare MUS_OBTAIN_ITEM
msgbox Text_Obtainedbox, MSGBOX_DEFAULT
waitfanfare
closemessage
giveitem ITEM_OAKS_PARCEL
msgbox Text_okciao MSGBOX_DEFAULT
closemessage
applymovement 8, move_rivalending
waitmovement 0
applymovement OBJ_EVENT_ID_PLAYER, move_faceleft
waitmovement 0
removeobject 8
savebgm MUS_DUMMY
fadedefaultbgm
special HealPlayerParty
setflag FLAG_UNUSED_0x021
setvar VAR_UNUSED_0x4091, 1
releaseall
end

Text_okciao:
.string "Gile: Ti ho rubato anche troppo\n"
.string "tempo {PLAYER}, buona fortuna per\l"
.string "il tuo viaggio!$"

Text_Obtainedbox:
.string "{PLAYER} ha ottenuto la Scatola di\n"
.string "dolci!$"

Text_finalchat:
.string "Gile: Che maleducato! La prossima\n"
.string "volta, io e il mio Goomy gli\l"
.string "daremo una bella lezione! In ogni\l"
.string "caso, {PLAYER}, ti consiglio di\l"
.string "andare a fare visita al Prof.\l"
.string "Sherman, è un grande studioso, ma\l"
.string "anche un grande appetito per i\l"
.string "dolci! Portagli questa scatola di\l"
.string "pasticcini e vedrai che ti darà\l"
.string "delle dritte!$"

move_sususxsx:
walk_up
walk_left
walk_left
walk_left
step_end

move_downleftleftleft:
walk_down
walk_left
walk_left
walk_left
step_end

Text_final:
.string "Ron: Non mi interessa nulla di\n"
.string "chi sia questo Sherman. Però ho\l"
.string "sentito che c'è un Laboratorio\l"
.string "Pokémon proprio a Mascar, la\l"
.string "prossima città. Ci rivedremo\l"
.string "{PLAYER}. La prossima volta, la\l"
.string "vittoria sarà mia!$"

move_playerafterfight:
walk_down
walk_right
step_end

move_playerafterfighttilesotto:
walk_up
walk_right
step_end

move_rivaltia:
walk_left
walk_left
walk_left
step_end

move_faceleft:
face_left
step_end

move_faceup:
face_up
step_end

move_facedown:
face_down
step_end

Text_Rivalvstia:
.string "Ron: Ma quanto parli! Non avevo\n"
.string "capito intendessi Camilla, di\l"
.string "Sinnoh. E' ovvio che sappiamo chi\l"
.string "sia, ma è impossibile che lei\l"
.string "perda tempo con una come te.\l"
.string "Ho già perso anche troppo tempo!$"

Text_tia4:
.string "Gile: Certo che voi due, non sapete\n"
.string "proprio un bel niente! Il Prof.\l"
.string "Sherman è il più grande studioso\l"
.string "della regione di Ancar! Conosce le\l"
.string "vostre famiglie e mi ha parlato di\l"
.string "voi. Tu devi essere {PLAYER}, tu\l"
.string "invece sei Ron.$"

Text_tia3:
.string "Gile: Ma come?! Non ditemi che non\n"
.string "conoscete Camilla, la campionessa\l"
.string "di Sinnoh!? E' una delle più forti\l"
.string "allenatrici al MONDO! Spero di\l"
.string "poterle chiedere un autografo, nel\l"
.string "caso dovessi riuscire ad\l"
.string "incontrarla! Oh, sarebbe il\l"
.string "miglior giorno della mia vita! In\l"
.string "ogni caso..il Prof. Sherman mi ha\l"
.string "parlato di voi due. Mi ha detto\l"
.string "che due ragazzi si sono trasferiti\l"
.string "a Bell, la cittadina dove aveva\l"
.string "sede il suo laboratorio.$"

Text_tia2:
.string "???: Mi chiamo Gile e ho assistito\n"
.string "alla vostra lotta! Devo dire che\l"
.string "siete in gamba! Anche io ho\l"
.string "iniziato ad allevare i Pokémon da\l"
.string "poco tempo, con l'obiettivo di\l"
.string "diventare forte come il mio\l"
.string "idolo, Camy!$"

Text_Gile:
.string "???: Complimenti per la lotta,\n"
.string "ragazzi!$"

Percorso3_Text_RivalDefeat:
.string "Ron: Io e il mio Aron, abbiamo\nperso?..$"

Text_rival3:
.string "Ron: Devo ammettere, che non mi\n"
.string "aspettavo di perdere. Se ho perso,\l"
.string "non è colpa del mio Aron,\l"
.string "lui ha dato tutto se stesso. E'\l"
.string "evidente che devo catturare altre\l"
.string "specie di Pokémon se voglio\l"
.string "diventare più forte e incontrare\l"
.string "mio padre. Quando arriverà quel\l"
.string "momento, lo sfiderò e lo\l"
.string "costringerò a tornare! Hai vinto,\l"
.string "ma non succederà ancora. Mi\l"
.string "prenderò la mia rivincita!$" 

Text_rival2:
.string "Ron: Non ho ancora capito chi tu\n"
.string "sia, ma sembra tu abbia la mia\l"
.string "stessa età. Ho capito ormai, tu\l"
.string "devi far parte della famiglia che\l"
.string "si è trasferita come noi, a Bell.\l"
.string "Da quel che vedo, sembri un\l"
.string "allenatore, ma lo sono anche io.\l"
.string "Il mio Pokémon, Aron, è l'amico\l"
.string "migliore che potessi desiderare.\l"
.string "Dato che hai origliato, saprai che\l"
.string "voglio incontrare mio padre.\l"
.string "Nessuno mi impedirà di raggiungere\l"
.string "il mio obiettivo, quindi, che ne\l"
.string "dici di una lotta? Vediamo se\l"
.string "oltre ad origliare, sei anche\l"
.string "capace a lottare!$"

move_rival:
walk_left
walk_left
walk_left
walk_left
walk_left
walk_left
step_end

Text_rival1:
.string "Ron: Ehy tu!$"

move_faceright:
face_right
step_end

move_interrogativo:
emote_question_mark
step_end

EventScript_finish::
releaseall
end

Percorso3_EventScript_RivalTilesotto::
compare VAR_UNUSED_0x4091, 0
goto_if_gt EventScript_finish
playbgm MUS_RG_ENCOUNTER_RIVAL, TRUE
addobject 7
setobjectxy 7, 46 11
setobjectmovementtype 7, MOVEMENT_TYPE_FACE_LEFT
msgbox Text_rival1, MSGBOX_DEFAULT
closemessage
applymovement OBJ_EVENT_ID_PLAYER, move_interrogativo
waitmovement 0
applymovement OBJ_EVENT_ID_PLAYER move_faceright
waitmovement 0
applymovement 7, move_rival
waitmovement 0
msgbox Text_rival2, MSGBOX_DEFAULT
closemessage
trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_103_MUDKIP, Percorso3_Text_RivalDefeat
msgbox Text_rival3, MSGBOX_DEFAULT
addobject 8
setobjectxy 8, 46 10
setobjectmovementtype 8, MOVEMENT_TYPE_FACE_RIGHT
msgbox Text_Gile, MSGBOX_DEFAULT
closemessage
applymovement 7, move_interrogativo
applymovement OBJ_EVENT_ID_PLAYER, move_interrogativo
waitmovement 0
applymovement 7, move_faceright
applymovement OBJ_EVENT_ID_PLAYER, move_faceright
waitmovement 0
applymovement OBJ_EVENT_ID_PLAYER, move_playerafterfighttilesotto
waitmovement 0
applymovement 8, move_rivaltia
waitmovement 0
msgbox Text_tia2 MSGBOX_DEFAULT
closemessage
applymovement 7, move_interrogativo
applymovement OBJ_EVENT_ID_PLAYER, move_interrogativo
waitmovement 0
msgbox Text_tia3 MSGBOX_DEFAULT
closemessage
applymovement 7, move_interrogativo
applymovement OBJ_EVENT_ID_PLAYER, move_interrogativo
waitmovement 0
msgbox Text_tia4 MSGBOX_DEFAULT
closemessage
msgbox Text_Rivalvstia MSGBOX_DEFAULT
closemessage
applymovement 7, move_faceup
applymovement OBJ_EVENT_ID_PLAYER, move_facedown
waitmovement 0
msgbox Text_final MSGBOX_DEFAULT
closemessage
applymovement 7, move_rivalending
applymovement OBJ_EVENT_ID_PLAYER, move_faceleft
waitmovement 0
applymovement 8, move_downleftleftleft
waitmovement 0
removeobject 7
applymovement 8, move_faceup
applymovement OBJ_EVENT_ID_PLAYER, move_facedown
waitmovement 0
msgbox Text_finalchat MSGBOX_DEFAULT
closemessage
playfanfare MUS_OBTAIN_ITEM
msgbox Text_Obtainedbox, MSGBOX_DEFAULT
waitfanfare
closemessage
giveitem ITEM_OAKS_PARCEL
msgbox Text_okciao MSGBOX_DEFAULT
closemessage
applymovement 8, move_rivalending
waitmovement 0
applymovement OBJ_EVENT_ID_PLAYER, move_faceleft
waitmovement 0
removeobject 8
savebgm MUS_DUMMY
fadedefaultbgm
special HealPlayerParty
setflag FLAG_UNUSED_0x021
setvar VAR_UNUSED_0x4091, 1
releaseall
end

move_rivalending:
walk_left
walk_left
walk_left
walk_left
walk_left
walk_left
walk_left
walk_left
walk_left
walk_left
emote_exclamation_mark
step_end

Percorso3_EventScript_Ivan::
trainerbattle_single TRAINER_IVAN, Percorso3_Text_IvanIntro, Percorso3_Text_IvanDefeated
msgbox Percorso3_Text_IvanPostbattle MSGBOX_AUTOCLOSE
end

Percorso3_EventScript_Becky::
trainerbattle_single TRAINER_BECKY, Percorso3_Text_BeckyIntro, Percorso3_Text_BeckyDefeated
msgbox Percorso3_Text_BeckyPostbattle MSGBOX_AUTOCLOSE
end

Percorso3_EventScript_Davis::
trainerbattle_single TRAINER_DAVIS, Percorso3_Text_DavisIntro, Percorso3_Text_DavisDefeated
msgbox Percorso3_Text_DavisPostbattle MSGBOX_AUTOCLOSE
end

Percorso3_EventScript_Lyle::
trainerbattle_single TRAINER_LYLE, Percorso3_Text_LyleIntro, Percorso3_Text_LyleDefeated
msgbox Percorso3_Text_LylePostbattle MSGBOX_AUTOCLOSE
end

Percorso3_EventScript_Edward::
trainerbattle_single TRAINER_EDWARD, Percorso3_Text_EdwardIntro, Percorso3_Text_EdwardDefeated
msgbox Percorso3_Text_EdwardPostbattle MSGBOX_AUTOCLOSE
end

Percorso3_EventScript_Sawyer_1::
trainerbattle_single TRAINER_SAWYER_1, Percorso3_Text_Sawyer1Intro, Percorso3_Text_Sawyer1Defeated
msgbox Percorso3_Text_Sawyer1Postbattle MSGBOX_AUTOCLOSE
end

Percorso3_Text_IvanIntro:
.string "I Pokémon vanno pescati!$"

Percorso3_Text_IvanDefeated:
.string "Devo ancora fare tanta\n"
.string "esperienza..$"

Percorso3_Text_IvanPostbattle:
.string "Tu si che sei abile con le lotte!$"

Percorso3_Text_BeckyIntro:
.string "Sono pronta a sfidarti!$"

Percorso3_Text_BeckyDefeated:
.string "Pronta a perdere..$"

Percorso3_Text_BeckyPostbattle:
.string "Vuoi un consiglio? Cattura più\n"
.string "Pokémon che puoi!$"

Percorso3_Text_DavisIntro:
.string "Ti mostrerò cosa sanno fare i miei\n"
.string "Pokémon Coleottero!$"

Percorso3_Text_DavisDefeated:
.string "Ugh, non ci voleva!$"

Percorso3_Text_DavisPostbattle:
.string "A te non piacciono i Pokémon\n"
.string "Coleottero?$"

Percorso3_Text_LyleIntro:
.string "Forza, sono prontissimo!$"

Percorso3_Text_LyleDefeated:
.string "Capita di perdere..$"

Percorso3_Text_LylePostbattle:
.string "I Pokémon Coleottero possono\n"
.string "evolversi abbastanza velocemente.$"

Percorso3_Text_EdwardIntro:
.string "Credi nei poteri psichici?$"

Percorso3_Text_EdwardDefeated:
.string "Che portento!$"

Percorso3_Text_EdwardPostbattle:
.string "Credo nei fenomeni paranormali.$"

Percorso3_Text_Sawyer1Intro:
.string "Forza, GEODUDE! Prepariamoci alla\n"
.string "sfida!$"

Percorso3_Text_Sawyer1Defeated:
.string "Perbacco, tu sì che sei un osso\n"
.string "duro!$"

Percorso3_Text_Sawyer1Postbattle:
.string "Ho catturato il mio Geodude in una\n"
.string "Grotta.$"

Route102_EventScript_Calvin:: @ 81EC105
	trainerbattle_single TRAINER_CALVIN_1, Route102_Text_CalvinIntro, Route102_Text_CalvinDefeated, Route102_EventScript_CalvinRegisterMatchCallAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, TRUE
	goto_if_eq Route102_EventScript_CalvinRematch
	setvar VAR_0x8004, TRAINER_CALVIN_1
	specialvar VAR_RESULT, IsTrainerRegistered
	compare VAR_RESULT, FALSE
	goto_if_eq Route102_EventScript_CalvinTryRegister
	msgbox Route102_Text_CalvinPostBattle, MSGBOX_DEFAULT
	release
	end

Route102_EventScript_CalvinRegisterMatchCallAfterBattle:: @ 81EC146
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	goto_if_set FLAG_HAS_MATCH_CALL, Route102_EventScript_CalvinRegisterMatchCall
	release
	end

Route102_EventScript_CalvinRegisterMatchCall:: @ 81EC157
	msgbox Route102_Text_CalvinRegisterShort, MSGBOX_DEFAULT
	register_matchcall TRAINER_CALVIN_1
	release
	end

Route102_EventScript_CalvinTryRegister:: @ 81EC170
	goto_if_set FLAG_HAS_MATCH_CALL, Route102_EventScript_CalvinRegister
	msgbox Route102_Text_CalvinPostBattle, MSGBOX_DEFAULT
	release
	end

Route102_EventScript_CalvinRegister:: @ 81EC183
	msgbox Route102_Text_CalvinRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_CALVIN_1
	release
	end

Route102_EventScript_CalvinRematch:: @ 81EC19C
	trainerbattle_rematch TRAINER_CALVIN_1, Route102_Text_CalvinRematchIntro, Route102_Text_CalvinRematchDefeated
	msgbox Route102_Text_CalvinRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route102_EventScript_Rick:: @ 81EC1B3
	trainerbattle_single TRAINER_RICK, Route102_Text_RickIntro, Route102_Text_RickDefeated
	msgbox Route102_Text_RickPostBattle, MSGBOX_AUTOCLOSE
	end

Route102_EventScript_Tiana:: @ 81EC1CA
	trainerbattle_single TRAINER_TIANA, Route102_Text_TianaIntro, Route102_Text_TianaDefeated
	msgbox Route102_Text_TianaPostBattle, MSGBOX_AUTOCLOSE
	end

Route102_EventScript_Allen:: @ 81EC1E1
	trainerbattle_single TRAINER_ALLEN, Route102_Text_AllenIntro, Route102_Text_AllenDefeated
	msgbox Route102_Text_AllenPostBattle, MSGBOX_AUTOCLOSE
	end

Route102_Text_WatchMeCatchPokemon: @ 81EC1F8
	.string "WALLY: {PLAYER}…\n"
	.string "POKéMON hide in tall grass like this,\l"
	.string "don't they?\p"
	.string "Please watch me and see if I can\n"
	.string "catch one properly.\p"
	.string "…Whoa!$"

Route102_Text_WallyIDidIt: @ 81EC271
	.string "WALLY: I did it… It's my…\n"
	.string "My POKéMON!$"

Route102_Text_LetsGoBack: @ 81EC297
	.string "{PLAYER}, thank you!\n"
	.string "Let's go back to the GYM!$"

Route102_Text_ImNotVeryTall: @ 81EC2C0
	.string "I'm…not very tall, so I sink right\n"
	.string "into tall grass.\p"
	.string "The grass goes up my nose and…\n"
	.string "Fwafwafwafwafwa…\p"
	.string "Fwatchoo!$"

Route102_Text_CatchWholeBunchOfPokemon: @ 81EC32E
	.string "I'm going to catch a whole bunch of\n"
	.string "POKéMON!$"

Route102_Text_RouteSignOldale: @ 81EC35B
	.string "Percorso 3\n"
	.string "{RIGHT_ARROW} Timber\l"
	.string "{LEFT_ARROW} Mascar$"

Route102_Text_RouteSignPetalburg: @ 81EC373
	.string "ROUTE 102\n"
	.string "{LEFT_ARROW} PETALBURG CITY$"

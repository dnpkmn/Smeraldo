PetalburgCity_House1_MapScripts:: @ 8207799
	.byte 0

PetalburgCity_House1_EventScript_Man:: @ 820779A
	msgbox PetalburgCity_House1_Text_TravelingIsWonderful, MSGBOX_NPC
	end

PetalburgCity_House1_EventScript_Woman:: @ 82077A3
	msgbox PetalburgCity_House1_Text_GoOnAdventure, MSGBOX_NPC
	end

PetalburgCity_House1_Text_TravelingIsWonderful: @ 82077AC
	.string "Traveling is wonderful!\p"
	.string "When I was young, I roamed the seas\n"
	.string "and the mountains!$"

PetalburgCity_House1_Text_GoOnAdventure: @ 82077FB
	.string "Non c'è nulla di meglio che una\n"
	.string "bella tazza di caffè! E' lavazza!$"

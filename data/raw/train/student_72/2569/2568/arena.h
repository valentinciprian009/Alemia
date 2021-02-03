#pragma once
#include"ConsoleInput.h"
#include "ConsoleOutput.h"
#include<iostream>
#include<vector>
#include "mouse_input.h"
#include <chrono>

#include "Pea.h";
#include "zombies.h"

class arena
{
	public:
		vector<entity*> L1;
		vector<entity*> L2;
		vector<entity*> L3;
		vector<entity*> L4;
		vector<entity*> L5;
		bool L1_mod[8] = { true,true,true,true,true,true,true,true };
		bool L2_mod[8] = { true,true,true,true,true,true,true,true };
		bool L3_mod[8] = { true,true,true,true,true,true,true,true };
		bool L4_mod[8] = { true,true,true,true,true,true,true,true };
		bool L5_mod[8] = { true,true,true,true,true,true,true,true };

		int zombie_nr;
		int BucketHeadZombie_nr;
		int PoleVaultingZombie_nr;
		int SuperZombie_nr;

		int Sunflower_nr;
		int score;

		int first_x;
		int first_y;
		int nr;
		std::chrono::steady_clock::time_point begin;
		std::chrono::steady_clock::time_point end;

		arena(int x, int y, int nr) {
			first_x = x;
			first_y = y;
			this->nr = nr;
			begin = std::chrono::steady_clock::now();
			end = std::chrono::steady_clock::now();
			
			Sunflower_nr = 0;
			score = 0;

			if (nr == 1){
				zombie_nr=5;
				BucketHeadZombie_nr=1;
				PoleVaultingZombie_nr=1;
				SuperZombie_nr=1;
			}
			else if (nr == 2) {
				zombie_nr = 10;
				BucketHeadZombie_nr = 2;
				PoleVaultingZombie_nr = 3;
				SuperZombie_nr = 1;
			}
			else if (nr == 3) {
				zombie_nr = 12;
				BucketHeadZombie_nr = 5;
				PoleVaultingZombie_nr = 5;
				SuperZombie_nr = 1;
			}

			for (int i = 0; i < 8; i++) {
				if (nr >= 2){
					entity* b = new entity(first_x + i * 10, first_y + 4);
					L2.push_back(b);

					entity* d = new entity(first_x + i * 10, first_y + 12);
					L4.push_back(d);
				}
				
				if (nr >= 3){
					entity* a = new entity(first_x + i * 10, first_y);
					L1.push_back(a);

					entity* e = new entity(first_x + i * 10, first_y + 16);
					L5.push_back(e);
				}

				entity* c = new entity(first_x + i * 10, first_y+8);
				L3.push_back(c);
			}
		}

		bool check_L_mouse_input(vector<entity*>& L, bool* L_mod, mouse_input inp, entity* curent)
		{
			entity* aux = curent;
			if ((inp.x >= first_x) && (inp.x < first_x + 10) && ((L[0]->name == "entity") || (L[0]->name == "pea") || (L[0]->name == "frozen_pea"))){
				curent->clear();
				L_mod[0] = true;
				L[0] = aux;
				L[0]->LEFT_DOWN_x = first_x;
				L[0]->LEFT_DOWN_y = L[2]->LEFT_DOWN_y;
				return true;
			}

			else if ((inp.x >= first_x+10) && (inp.x < first_x + 20) && ((L[1]->name == "entity")|| (L[1]->name == "pea") || (L[1]->name == "frozen_pea"))){
				curent->clear();
				L_mod[1] = true;
				L[1] = aux;
				L[1]->LEFT_DOWN_x = first_x+10;
				L[1]->LEFT_DOWN_y = L[2]->LEFT_DOWN_y;
				return true;
			}

			else if ((inp.x >= first_x+20) && (inp.x < first_x + 30) && ((L[2]->name == "entity") || (L[2]->name == "pea") || (L[2]->name == "frozen_pea"))) {
				curent->clear();
				L_mod[2] = true;
				L[2] = aux;
				L[2]->LEFT_DOWN_x = first_x+20;
				L[2]->LEFT_DOWN_y = L[3]->LEFT_DOWN_y;
				return true;
			}

			else if ((inp.x >= first_x+30) && (inp.x < first_x + 40) && ((L[3]->name == "entity") || (L[3]->name == "pea") || (L[3]->name == "frozen_pea"))){
				curent->clear();
				L_mod[3] = true;
				L[3] = aux;
				L[3]->LEFT_DOWN_x = first_x+30;
				L[3]->LEFT_DOWN_y = L[2]->LEFT_DOWN_y;
				return true;
			}

			else if ((inp.x >= first_x+40) && (inp.x < first_x + 50) && ((L[4]->name == "entity") || (L[4]->name == "pea") || (L[4]->name == "frozen_pea"))){
				curent->clear();
				L_mod[4] = true;
				L[4] = aux;
				L[4]->LEFT_DOWN_x = first_x+40;
				L[4]->LEFT_DOWN_y = L[2]->LEFT_DOWN_y;
				return true;
			}

			else if ((inp.x >= first_x+50) && (inp.x < first_x + 60) && ((L[5]->name == "entity") || (L[5]->name == "pea") || (L[5]->name == "frozen_pea"))){
				curent->clear();
				L_mod[5] = true;
				L[5] = aux;
				L[5]->LEFT_DOWN_x = first_x+50;
				L[5]->LEFT_DOWN_y = L[2]->LEFT_DOWN_y;
				return true;
			}

			else if ((inp.x >= first_x+60) && (inp.x < first_x + 70) && ((L[6]->name == "entity") || (L[6]->name == "pea") || (L[6]->name == "frozen_pea"))){
				curent->clear();
				L_mod[6] = true;
				L[6] = aux;
				L[6]->LEFT_DOWN_x = first_x+60;
				L[6]->LEFT_DOWN_y = L[2]->LEFT_DOWN_y;
				return true;
			}

			else if ((inp.x >= first_x+70) && (inp.x < first_x + 80) && ((L[7]->name == "entity") || (L[7]->name == "pea") || (L[7]->name == "frozen_pea"))) {
				curent->clear();
				L_mod[7] = true;
				L[7] = aux;
				L[7]->LEFT_DOWN_x = first_x+70;
				L[7]->LEFT_DOWN_y = L[2]->LEFT_DOWN_y;
				return true;
			}
			else {
				return false;
			}
		}

		int run(mouse_input inp ,entity*& curent)
		{
			if (curent->name != "entity") {
				check_mouse_input_y(inp, curent);
			}
			if ((spawn_zombie_pick_lane() == false)&&(check_zombies_exists() == false))
			{
				return 1;
			}
			
			run_all_lines();
			print_arena();

			if (check_lost() == true) {
				
				return -1;
			}

			return 0;
		}

		void spawn_zombie_in_lane(vector<entity*>& L) 
		{
			int x = rand() % 4 + 1;

			if ((x == 1)&&(zombie_nr>0)) {
				L[7] = new zombie(first_x + 70, L[1]->LEFT_DOWN_y);
				zombie_nr--;
				L[7]->print();
			}
			if ((x == 2) && (BucketHeadZombie_nr > 0)) {
				L[7] = new BucketHeadZombie(first_x + 70, L[1]->LEFT_DOWN_y);
				BucketHeadZombie_nr--;
				L[7]->print();
			}
			if ((x == 3) && (PoleVaultingZombie_nr > 0)){
				PoleVaultingZombie_nr--;
				L[7] = new PoleVaultingZombie(first_x + 70, L[1]->LEFT_DOWN_y);
				L[7]->print();
			}
			if ((x == 4) && (SuperZombie_nr > 0)) {
				SuperZombie_nr--;
				L[7] = new SuperZombie(first_x + 70, L[1]->LEFT_DOWN_y);
				L[7]->print();
			}
		}

		bool spawn_zombie_pick_lane()
		{
			if ((zombie_nr <= 0) && (BucketHeadZombie_nr <= 0) && (SuperZombie_nr <= 0) && (PoleVaultingZombie_nr <= 0))
			{
				return false;
			}
			else {
				end = std::chrono::steady_clock::now();
				int x = 3;
				if (std::chrono::duration_cast<std::chrono::seconds>(end - begin).count() > 2)
				{
					begin = std::chrono::steady_clock::now();
					if (nr == 2) {
						x = rand() % 3 + 2;
					}

					if (nr == 3) {
						x = rand() % 5 + 1;
					}

					if (x == 1) {
						spawn_zombie_in_lane(L1);
					}
					else if (x == 2) {
						spawn_zombie_in_lane(L2);
					}
					else if (x == 3) {
						spawn_zombie_in_lane(L3);
					}
					else if (x == 4) {
						spawn_zombie_in_lane(L4);
					}
					else if (x == 5) {
						spawn_zombie_in_lane(L5);
					}
				}
				return true;
			}
		}

		void check_mouse_input_y(mouse_input inp, entity*& curent)
		{
			if ((inp.x >= first_x) && (inp.x <= first_x + 80))
			{
				if (nr >= 3) {

					if ((inp.y > first_y - 4) && (inp.y < first_y))
					{
						if (check_L_mouse_input(L1, L1_mod, inp, curent) == true){
							if (curent->name == "Sunflower") {
								Sunflower_nr++;
							}
							curent = new entity(curent->LEFT_DOWN_x, curent->LEFT_DOWN_y);
							curent->clear();
						}	
					}

					if ((inp.y > first_y + 12) && (inp.y < first_y + 16))
					{
						if (check_L_mouse_input(L5, L5_mod, inp, curent) == true) {
							if (curent->name == "Sunflower") {
								Sunflower_nr++;
							}
							curent = new entity(curent->LEFT_DOWN_x, curent->LEFT_DOWN_y);
							curent->clear();
						}
					}
				}

				if (nr >= 2) {
					if ((inp.y > first_y) && (inp.y < first_y + 4))
					{
						if (check_L_mouse_input(L2, L2_mod, inp, curent) == true) {
							if (curent->name == "Sunflower") {
								Sunflower_nr++;
							}
							curent = new entity(curent->LEFT_DOWN_x, curent->LEFT_DOWN_y);
							curent->clear();
						}
					}

					if ((inp.y > first_y + 8) && (inp.y < first_y + 12))
					{
						if (check_L_mouse_input(L4, L4_mod, inp, curent) == true) {
							if (curent->name == "Sunflower") {
								Sunflower_nr++;
							}
							curent = new entity(curent->LEFT_DOWN_x, curent->LEFT_DOWN_y);
							curent->clear();
						}
					}
				}

				if ((inp.y > first_y + 4) && (inp.y < first_y + 8))
				{
					if (check_L_mouse_input(L3, L3_mod, inp, curent) == true) {
						if (curent->name == "Sunflower") {
							Sunflower_nr++;
						}
						curent = new entity(curent->LEFT_DOWN_x, curent->LEFT_DOWN_y);
						curent->clear();
					}
				}
			}
		}

		void print_arena(){
			if (nr >= 2) {
				print_line(L2, L2_mod);
				print_line(L4, L4_mod);
			}

			if (nr >= 3) {
				print_line(L1, L1_mod);
				print_line(L5, L5_mod);
			}
			print_line(L3, L3_mod);
		}

		void print_line(vector<entity*> L, bool* L_mod){
			for (int i = 0; i < 8; i++){
				if (L_mod[i] == true) {
					L[i]->print();
					L_mod[i] = false;
				}
			}
		}

		void run_all_lines()
		{
			if (nr >= 2) {
				run_line(L2, L2_mod);
				run_line(L4, L4_mod);
			}

			if (nr >= 3) {
				run_line(L1, L1_mod);
				run_line(L5, L5_mod);
			}
			run_line(L3, L3_mod);
		}

		void run_line(vector<entity*>& L, bool* L_mod)
		{
			for (int i = 0; i < 8; i++)
			{
				L[i]->run(L, L_mod, i, Sunflower_nr, score);
			}
		}

		bool check_zombies_exists() {
			for (int i = 0; i <= 7; i++) {
				if (nr >= 2)
				{
					if ((L2[i]->name == "zombie") || (L2[i]->name == "SuperZombie") || (L2[i]->name == "PoleVaultingZombie") || (L2[i]->name == "BucketHeadZombie")) {
						return true;
					}
					if ((L4[i]->name == "zombie") || (L4[i]->name == "SuperZombie") || (L4[i]->name == "PoleVaultingZombie") || (L4[i]->name == "BucketHeadZombie")) {
						return true;
					}
				}
				if (nr >= 3)
				{
					if ((L5[i]->name == "zombie") || (L5[i]->name == "SuperZombie") || (L5[i]->name == "PoleVaultingZombie") || (L5[i]->name == "BucketHeadZombie")) {
						return true;
					}
					if ((L1[i]->name == "zombie") || (L1[i]->name == "SuperZombie") || (L1[i]->name == "PoleVaultingZombie") || (L1[i]->name == "BucketHeadZombie")) {
						return true;
					}
				}
				if ((L3[i]->name == "zombie") || (L3[i]->name == "SuperZombie") || (L3[i]->name == "PoleVaultingZombie") || (L3[i]->name == "BucketHeadZombie")) {
					return true;
				}
			}
			return false;
		}

		bool check_lost()
		{
			if (nr >= 3) {
				if ((L1[0]->name == "zombie") || (L1[0]->name == "SuperZombie") || (L1[0]->name == "PoleVaultingZombie") || (L1[0]->name == "BucketHeadZombie")) {
					return true;
				}
				if ((L5[0]->name == "zombie") || (L5[0]->name == "SuperZombie") || (L5[0]->name == "PoleVaultingZombie") || (L5[0]->name == "BucketHeadZombie")) {
					return true;
				}
				
			}

			else if ((L3[0]->name == "zombie") || (L3[0]->name == "SuperZombie") || (L3[0]->name == "PoleVaultingZombie") || (L3[0]->name == "BucketHeadZombie")) {
				return true;
			}

			if (nr >= 2) {
				if ((L2[0]->name == "zombie") || (L2[0]->name == "SuperZombie") || (L2[0]->name == "PoleVaultingZombie") || (L2[0]->name == "BucketHeadZombie")) {
					return true;
				}
				if ((L4[0]->name == "zombie") || (L4[0]->name == "SuperZombie") || (L4[0]->name == "PoleVaultingZombie") || (L4[0]->name == "BucketHeadZombie")) {
					return true;
				}
			}
				
			if ((L3[0]->name == "zombie") || (L3[0]->name == "SuperZombie") || (L3[0]->name == "PoleVaultingZombie") || (L3[0]->name == "BucketHeadZombie")) {
				return true;
			}

			return false;
		}
};


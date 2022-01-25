#pragma once


class CActions
{
private:
	CActions();
	static CActions*Instance;
public:
	void				game();
	void				clean_screen();
	int					select_level();
	void				read_id();
	void				print_LOGO();
	void				print_Level();
	void				print_GAME_OVER();
	void				print_Victory();

	void				log_sign_in(const char*username);
	void				log_select_level(int level);
	void				log_victory(int score);
	void				log_game_over();

	static				CActions& getInstance();
	static void			destroyInstance();
	~CActions();
};


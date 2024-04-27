
#include <a_samp>
#include <discord-connector>

#define DCMD_PREFIX "."
#include <discord-cmd>
#include <dini>



new static 
	Mode = 0,
	Perm_Mode = 0; // 3 modes


forward Config::DatabaseInit();
forward Config::DatabaseExit();
forward User::DatabaseLoad(DCC_User:user);
forward User::DatabaseSave(DCC_User:user);


public Config::DatabaseInit()
{
	new config_path[32];
	format(config_path, sizeof(config_path), "Admina/Database/Config/config.cfg");
	if(dini_Exists(config_path))
	{
		Mode = dini_Int(config_path, "VISUAL_MODE");
		Perm_Mode = dini_Int(config_path, "PERM_MODE");
	}
	return 1;
}

public Config::DatabaseExit()
{
	new config_path[32];
	format(config_path, sizeof(config_path), "Admina/Database/Config/config.cfg");
	if(dini_Exists(config_path))
	{
		//Mode = dini_Int(config_path, "VISUAL_MODE");
		dini_SetInt(config_path, "VISUAL_MODE", Mode);
		dini_SetInt(config_path, "PERM_MODE", Perm_Mode);
	}
	return 1;
}

public User::DatabaseSave(DCC_User:user)
{
	new user_path[32*2], DCC_User:user_name[DCC_USERNAME_SIZE];
	format(user_path, sizeof(user_path), "Admina/Database/Users/User-[%s].ini", DCC_GetUserName(user, user_name[DCC_USERNAME_SIZE], sizeof(user_name)));
	if(dini_Exists(user_path))
	{
		// do something
	}
	return 1;
}

public User::DatabaseLoad(DCC_User:user)
{
	new user_path[32*2], DCC_User:user_name[DCC_USERNAME_SIZE];
	format(user_path, sizeof(user_path), "Admina/Database/Users/User-[%s].ini", DCC_GetUserName(user, user_name[DCC_USERNAME_SIZE], sizeof(user_name)));
	if(dini_Exists(user_path))
	{
		// do something
	}
	return 1;
}

struct passwd* (*getpwnam_orig)( const char* name );
struct passwd* (*getpwuid_orig)( uid_t uid );
char faked_pw_dir[] = "/accounts/devuser";

struct passwd* getpwnam( const char* name )
{
	struct passwd* obj;

	if (getpwnam_orig == NULL)
		getpwnam_orig = dlsym(RTLD_NEXT, "getpwnam");

	obj = getpwnam_orig(name);
	if (!obj)
		return NULL;

	if (!strcmp(name, "root"))
		obj->pw_dir = (char *) &faked_pw_dir;

	return obj;
}
struct passwd* getpwuid( uid_t uid )
{
	struct passwd* obj;

	if (getpwuid_orig == NULL)
		getpwuid_orig = dlsym(RTLD_NEXT, "getpwuid");

	obj = getpwuid_orig(uid);
        if (!obj)
                return NULL;

	if (uid == 0)
		obj->pw_dir = (char *) &faked_pw_dir;

	return obj;
}


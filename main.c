#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/resource.h>

extern size_t	ft_strlen(const char *s);
extern int		ft_strcmp(const char *s1, const char *s2);
extern char		*ft_strcpy(char *dest, const char *src);
extern ssize_t	ft_write(int fd, const void *buf, size_t count);
extern ssize_t	ft_read(int fd, void *buf, size_t count);
extern char		*ft_strdup(const char *s);

int				main(void)
{
	/*
	** input ""
	** input "ohmyassembly"
	** input "ohmyassembly" x 15
	*/
	const char	*blue = "\x1b[34m";
	const char	*reset = "\x1b[0m";
	const char	*purple = "\x1b[35m";
	const char	*yellow = "\x1b[33m";
	const char	*green = "\x1b[32m";
	const char	*red = "\x1b[31m";
	const char	*strs[] = {
		"",
		"ohmyassembly",
		"ohmyassemblyohmyassemblyohmyassemblyohmyassemblyohmyassemblyohmyassemblyohmyassemblyohmyassemblyohmyassemblyohmyassemblyohmyassemblyohmyassemblyohmyassemblyohmyassemblyohmyassembly",
		"ohmy",
		"\xff",
		"\xfd",
		"\xfe",
	};

	printf("%sF%sT%s_%sS%sT%sR%sL%sE%sN%s\n", red, green, yellow, purple, blue, red, green, yellow, purple, reset);
	printf("%s[original]: \"%s\"%s\n  [system strlen] : %lu\n  [ft strlen]     : %lu\n", blue, strs[0], reset, strlen(strs[0]), ft_strlen(strs[0]));
	printf("%s[original]: \"%s\"%s\n  [system strlen] : %lu\n  [ft strlen]     : %lu\n", blue, strs[1], reset, strlen(strs[1]), ft_strlen(strs[1]));
	printf("%s[original]: \"%s\" x 15%s\n  [system strlen] : %lu\n  [ft strlen]     : %lu\n", blue, strs[1], reset, strlen(strs[2]), ft_strlen(strs[2]));
	printf("\n");

	/*
	** s1 ""					s2 ""
	** s1 "ohmyassembly"		s2 ""
	** s1 ""					s2 "ohmyassembly"
	** s1 "ohmyassembly"		s2 "ohmyassembly"
	** s1 "ohmy"				s2 "ohmyassembly"
	** s1 "ohmyassembly"		s2 "ohmy"
	** s1 "ohmyassembly"		s2 "ohmyassembly" x 15
	** s1 "ohmyassembly" x 15	s2 "ohmyassembly"
	** s1 "ohmyassembly" x 15	s2 "ohmyassembly" x 15
	** s1 "\xff"				s2 "\xff"
	** s1 "\xfe"				s2 "\xfd"
	** s1 "\xfd"				s2 "\xfe"
	** s1 "\xff"				s2 ""
	** s1 ""					s2 "\xff"
	*/
	printf("%sF%sT%s_%sS%sT%sR%sC%sM%sP%s\n", red, green, yellow, purple, blue, red, green, yellow, purple, reset);
	printf("%s[original]: \"%s\" and \"%s\"%s\n  [system strcmp] : %d\n  [ft strcmp]     : %d\n", blue, strs[0], strs[0], reset, strcmp(strs[0], strs[0]), ft_strcmp(strs[0], strs[0]));
	printf("%s[original]: \"%s\" and \"%s\"%s\n  [system strcmp] : %d\n  [ft strcmp]     : %d\n", blue, strs[1], strs[0], reset, strcmp(strs[1], strs[0]), ft_strcmp(strs[1], strs[0]));
	printf("%s[original]: \"%s\" and \"%s\"%s\n  [system strcmp] : %d\n  [ft strcmp]     : %d\n", blue, strs[0], strs[1], reset, strcmp(strs[0], strs[1]), ft_strcmp(strs[0], strs[1]));
	printf("%s[original]: \"%s\" and \"%s\"%s\n  [system strcmp] : %d\n  [ft strcmp]     : %d\n", blue, strs[1], strs[1], reset, strcmp(strs[1], strs[1]), ft_strcmp(strs[1], strs[1]));
	printf("%s[original]: \"%s\" and \"%s\"%s\n  [system strcmp] : %d\n  [ft strcmp]     : %d\n", blue, strs[3], strs[1], reset, strcmp(strs[3], strs[1]), ft_strcmp(strs[3], strs[1]));
	printf("%s[original]: \"%s\" and \"%s\"%s\n  [system strcmp] : %d\n  [ft strcmp]     : %d\n", blue, strs[1], strs[3], reset, strcmp(strs[1], strs[3]), ft_strcmp(strs[1], strs[3]));
	printf("%s[original]: \"%s\" and \"%s\" x 15%s\n  [system strcmp] : %d\n  [ft strcmp]     : %d\n", blue, strs[1], strs[1], reset, strcmp(strs[1], strs[2]), ft_strcmp(strs[1], strs[2]));
	printf("%s[original]: \"%s\" x 15 and \"%s\"%s\n  [system strcmp] : %d\n  [ft strcmp]     : %d\n", blue, strs[1], strs[1], reset, strcmp(strs[2], strs[1]), ft_strcmp(strs[2], strs[1]));
	printf("%s[original]: \"%s\" x 15 and \"%s\" x 15%s\n  [system strcmp] : %d\n  [ft strcmp]     : %d\n", blue, strs[1], strs[1], reset, strcmp(strs[2], strs[2]), ft_strcmp(strs[2], strs[2]));
	printf("%s[original]: \"%s\" and \"%s\"%s\n  [system strcmp] : %d\n  [ft strcmp]     : %d\n", blue, strs[4], strs[4], reset, strcmp(strs[4], strs[4]), ft_strcmp(strs[4], strs[4]));
	printf("%s[original]: \"%s\" and \"%s\"%s\n  [system strcmp] : %d\n  [ft strcmp]     : %d\n", blue, strs[6], strs[5], reset, strcmp(strs[6], strs[5]), ft_strcmp(strs[6], strs[5]));
	printf("%s[original]: \"%s\" and \"%s\"%s\n  [system strcmp] : %d\n  [ft strcmp]     : %d\n", blue, strs[5], strs[6], reset, strcmp(strs[5], strs[6]), ft_strcmp(strs[5], strs[6]));
	printf("%s[original]: \"%s\" and \"%s\"%s\n  [system strcmp] : %d\n  [ft strcmp]     : %d\n", blue, strs[4], strs[0], reset, strcmp(strs[4], strs[0]), ft_strcmp(strs[4], strs[0]));
	printf("%s[original]: \"%s\" and \"%s\"%s\n  [system strcmp] : %d\n  [ft strcmp]     : %d\n", blue, strs[0], strs[4], reset, strcmp(strs[0], strs[4]), ft_strcmp(strs[0], strs[4]));
	printf("\n");

	/*
	** copy ""
	** copy "ohmyassembly"
	** copy "ohmyassembly" x 15
	** copy "ohmy"
	*/
	char		**in = malloc(sizeof(char*) * 5);
	in[0] = strdup("");
	in[1] = strdup("ohmyassembly");
	in[2] = strdup("ohmyassemblyohmyassemblyohmyassemblyohmyassemblyohmyassemblyohmyassemblyohmyassemblyohmyassemblyohmyassemblyohmyassemblyohmyassemblyohmyassemblyohmyassemblyohmyassemblyohmyassembly");
	in[3] = strdup("ohmy");
	in[4] = NULL;
	char		**sysout = malloc(sizeof(char*) * 5);
	sysout[0] = malloc(strlen(in[0]));
	sysout[1] = malloc(strlen(in[1]));
	sysout[2] = malloc(strlen(in[2]));
	sysout[3] = malloc(strlen(in[3]));
	sysout[4] = NULL;
	char		**ftout = malloc(sizeof(char*) * 5);
	ftout[0] = malloc(strlen(in[0]));
	ftout[1] = malloc(strlen(in[1]));
	ftout[2] = malloc(strlen(in[2]));
	ftout[3] = malloc(strlen(in[3]));
	ftout[4] = NULL;

	printf("%sF%sT%s_%sS%sT%sR%sC%sP%sY%s\n", red, green, yellow, purple, blue, red, green, yellow, purple, reset);
	printf("%s[input]: \"%s\"%s\n  [system strcpy out] : %s\n  [ft strcpy out]     : %s\n", blue, in[0], reset, strcpy(sysout[0], in[0]), ft_strcpy(ftout[0], in[0]));
	printf("%s[input]: \"%s\"%s\n  [system strcpy out] : %s\n  [ft strcpy out]     : %s\n", blue, in[1], reset, strcpy(sysout[1], in[1]), ft_strcpy(ftout[1], in[1]));
	printf("%s[input]: \"%s\"%s\n  [system strcpy out] : %s\n  [ft strcpy out]     : %s\n", blue, in[2], reset, strcpy(sysout[2], in[2]), ft_strcpy(ftout[2], in[2]));
	printf("%s[input]: \"%s\"%s\n  [system strcpy out] : %s\n  [ft strcpy out]     : %s\n", blue, in[3], reset, strcpy(sysout[3], in[3]), ft_strcpy(ftout[3], in[3]));
	printf("\n");

	/*
	** write ""						filedescriptor STDOUT
	** write "ohmyassembly"			filedescriptor STDOUT
	** write "ohmyassembly" x 15	filedescriptor STDOUT
	** write ""						filedescriptor FILE (x)
	** write "ohmyassembly"			filedescriptor FILE (v)
	** write "ohmyassembly" x 15	filedescriptor FILE (v)
	*/
	int			fd;

	// Open file for writing.
	fd = open("file.txt", O_TRUNC | O_CREAT | O_WRONLY, 0644);
	printf("%sF%sT%s_%sW%sR%sI%sT%sE%s\n", red, green, yellow, purple, blue, red, green, yellow, reset);
	printf("%s[buffer]: \"%s\"%s\n", blue, in[0], reset);
	printf("  [errno before] : %d\n", errno);
	printf("  [sys return]   : %ld\n", write(1, in[0], strlen(in[0])));
	printf("  [ft return]    : %ld\n", ft_write(1, in[0], strlen(in[0])));
	printf("  [errno after]  : %d\n", errno);
	printf("%s[buffer]: \"%s\"%s\n", blue, in[1], reset);
	printf("  [errno before] : %d\n", errno);
	printf("  [sys return]   : %ld\n", write(1, in[1], strlen(in[1])));
	printf("  [ft return]    : %ld\n", ft_write(1, in[1], strlen(in[1])));
	printf("  [errno after]  : %d\n", errno);
	printf("%s[buffer]: \"%s\"%s\n", blue, in[2], reset);
	printf("  [errno before] : %d\n", errno);
	printf("  [sys return]   : %ld\n", write(1, in[2], strlen(in[2])));
	printf("  [ft return]    : %ld\n", ft_write(1, in[2], strlen(in[2])));
	printf("  [errno after]  : %d\n", errno);
	printf("%s[buffer]: \"%s\"%s\n", blue, in[0], reset);
	printf("  [errno before] : %d\n", errno);
	printf("  [sys return]   : %ld\n", write(15, in[0], strlen(in[0])));
	printf("  [sys errno]    : %d\n", errno);
	errno = 0;
	printf("  [errno before] : %d\n", errno);
	printf("  [ft return]    : %ld\n", ft_write(15, in[0], strlen(in[0])));
	printf("  [ft errno]     : %d\n", errno);
	errno = 0;
	printf("%s[buffer]: \"%s\"%s\n", blue, in[1], reset);
	printf("  [errno before] : %d\n", errno);
	printf("  [sys return]   : %ld\n", write(fd, in[1], strlen(in[1])));
	printf("  [sys errno]    : %d\n", errno);
	errno = 0;
	printf("  [errno before] : %d\n", errno);
	printf("  [ft return]    : %ld\n", ft_write(fd, in[1], strlen(in[1])));
	printf("  [ft errno]     : %d\n", errno);
	printf("%s[buffer]: \"%s\"%s\n", blue, in[2], reset);
	printf("  [errno before] : %d\n", errno);
	printf("  [sys return]   : %ld\n", write(fd, in[2], strlen(in[2])));
	printf("  [sys errno]    : %d\n", errno);
	errno = 0;
	printf("  [errno before] : %d\n", errno);
	printf("  [ft return]    : %ld\n", ft_write(fd, in[2], strlen(in[2])));
	printf("  [ft errno]     : %d\n", errno);
	errno = 0;
	printf("\n");

	/*
	** read ""					filedescriptor FILE (v)
	** read "ohmyassembly"		filedescriptor FILE (v)
	** read "ohmyassembly" x 15	filedescriptor FILE (v)
	** read "ohmy"				filedescriptor FILE (x)				
	*/
	printf("%sF%sT%s_%sR%sE%sA%sD%s\n", red, green, yellow, purple, blue, red, green, reset);
	
	// Close the opened file for writing
	close(fd);

	// Open the file for reading only and
	fd = open("file.txt", O_RDONLY, 0644);

	// clear out buffers for read calls.
	for (int idx = 0; sysout[idx] != NULL; idx++)
		memset(sysout[idx], 0, strlen(in[idx]));
	for (int idx = 0; ftout[idx] != NULL; idx++)
		memset(ftout[idx], 0, strlen(in[idx]));

	printf("%s[sys buffer]: \"%s\" | [ft buffer]: \"%s\"%s\n", blue, sysout[0], ftout[0], reset);
	printf("  [errno before] : %d\n", errno);
	printf("  [sys return]   : %ld\n", read(fd, sysout[0], strlen(in[0])));
	printf("  [sys buffer]   : %s\n", sysout[0]);
	printf("  [ft return]    : %ld\n", ft_read(fd, ftout[0], strlen(in[0])));
	printf("  [ft buffer]    : %s\n", ftout[0]);
	printf("  [errno after]  : %d\n", errno);
	printf("%s[sys buffer]: \"%s\" | [ft buffer]: \"%s\"%s\n", blue, sysout[1], ftout[1], reset);
	printf("  [errno before] : %d\n", errno);
	printf("  [sys return]   : %ld\n", read(fd, sysout[1], strlen(in[1])));
	printf("  [sys buffer]   : %s\n", sysout[1]);
	printf("  [ft return]    : %ld\n", ft_read(fd, ftout[1], strlen(in[1])));
	printf("  [ft buffer]    : %s\n", ftout[1]);
	printf("  [errno after]  : %d\n", errno);
	printf("%s[sys buffer]: \"%s\" | [ft buffer]: \"%s\"%s\n", blue, sysout[2], ftout[2], reset);
	printf("  [errno before] : %d\n", errno);
	printf("  [sys return]   : %ld\n", read(fd, sysout[2], strlen(in[2])));
	printf("  [sys buffer]   : %s\n", sysout[2]);
	printf("  [ft return]    : %ld\n", ft_read(fd, ftout[2], strlen(in[2])));
	printf("  [ft buffer]    : %s\n", ftout[2]);
	printf("  [errno after]  : %d\n", errno);
	printf("%s[sys buffer]: \"%s\" | [ft buffer]: \"%s\"%s\n", blue, sysout[3], ftout[3], reset);
	printf("  [errno before] : %d\n", errno);
	printf("  [sys return]   : %ld\n", read(-1, sysout[3], strlen(in[3])));
	printf("  [sys buffer]   : %s\n", sysout[3]);
	printf("  [sys errno]    : %d\n", errno);
	errno = 0;
	printf("  [errno before] : %d\n", errno);
	printf("  [ft return]    : %ld\n", ft_read(-1, ftout[3], strlen(in[3])));
	printf("  [ft buffer]    : %s\n", ftout[3]);
	printf("  [ft errno]     : %d\n", errno);
	errno = 0;
	printf("\n");
	
	// Close the opened file for reading
	// and free malloced buffers.
	close(fd);
	for (int idx = 0; in[idx] != NULL; idx++)
		free(in[idx]);
	free(in);
	for (int idx = 0; sysout[idx] != NULL; idx++)
		free(sysout[idx]);
	free(sysout);
	for (int idx = 0; ftout[idx] != NULL; idx++)
		free(ftout[idx]);
	free(ftout);

	/*
	** duplicate ""
	** duplicate "ohmyassembly"
	** duplicate "ohmyassembly" x 15
	*/
	char		*dups[2];

	printf("%sF%sT%s_%sS%sT%sR%sD%sU%sP%s\n", red, green, yellow, purple, blue, red, green, yellow, purple, reset);	
	dups[0] = strdup("");
	dups[1] = ft_strdup("");
	printf("%s[original]: \"%s\"%s\n  [system strdup] : %s\n  [ft strdup]     : %s\n", blue, strs[0], reset, dups[0], dups[1]);
	free(dups[0]);
	free(dups[1]);
	dups[0] = strdup("ohmyassembly");
	dups[1] = ft_strdup("ohmyassembly");
	printf("%s[original]: \"%s\"%s\n  [system strdup] : %s\n  [ft strdup]     : %s\n", blue, strs[1], reset, dups[0], dups[1]);
	free(dups[0]);
	free(dups[1]);
	dups[0] = strdup("ohmyassemblyohmyassemblyohmyassemblyohmyassemblyohmyassemblyohmyassemblyohmyassemblyohmyassemblyohmyassemblyohmyassemblyohmyassemblyohmyassemblyohmyassemblyohmyassemblyohmyassembly");
	dups[1] = ft_strdup("ohmyassemblyohmyassemblyohmyassemblyohmyassemblyohmyassemblyohmyassemblyohmyassemblyohmyassemblyohmyassemblyohmyassemblyohmyassemblyohmyassemblyohmyassemblyohmyassemblyohmyassembly");
	printf("%s[original]: \"%s\" x 15%s\n  [system strdup] : %s\n  [ft strdup]     : %s\n", blue, strs[1], reset, dups[0], dups[1]);
	free(dups[0]);
	free(dups[1]);
	return (0);
}
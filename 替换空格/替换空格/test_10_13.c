#define _CRT_SECURE_NO_WARNINGS 1
char* replaceSpace(char* s){
	char *returned = calloc(strlen(s) * 3 + 1, sizeof(char));
	int i = 0, k = 0;
	while (s[i] != '\0'){
		if (s[i] == ' '){
			returned[k++] = '%';
			returned[k++] = '2';
			returned[k++] = '0';
			i++;
		}
		else{
			returned[k++] = s[i];
			i++;
		}
	}
	return returned;
}
#include <stdio.h>
#include <string.h>

int run_cmd(const char *cmd, char *result, int max_len)
{
	FILE *fp = NULL;
	int result_len = 0;

	memset(result, 0, max_len);
	fp = popen(cmd, "r");
	if (!fp)
		return 0;

	while(fgets(result + result_len, max_len - result_len - 1, fp)) {
		result_len += strlen(result + result_len);
		if(result_len + 1 == max_len)
			break;
	}

	pclose(fp);
	return result_len;
}

int main(void)
{
	int result_len;
	char cmd[128];
	char result[1024];
	snprintf(cmd, sizeof(cmd), "%s print_switch_ports", "~/c_test/run_cmd.sh");
	result_len = run_cmd(cmd, result, sizeof(result));
	printf("cmd: %s\n", cmd);
	printf("result: \n%s", result);
	printf("result_len: %d\n", result_len);

	return 0;
}

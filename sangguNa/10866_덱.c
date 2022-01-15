#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct	s_node
{
	int				data;
	struct s_node	*prev;
	struct s_node	*next;
}				t_node;

int N, i, cnt, data;
char command[11];
t_node *front, *back;

int main(void)
{
	front = (t_node *)malloc(sizeof(t_node));
	back = (t_node *)malloc(sizeof(t_node));

	front = NULL;
	back = NULL;

	scanf("%d", &N);

	for (i = 0; i < N; i++)
	{
		scanf("%s", &command);

		if (!strcmp(command, "push_front"))
		{
			t_node *new_data;
			new_data = (t_node *)malloc(sizeof(t_node));
			scanf("%d", &data);

			new_data->data = data;
			new_data->prev = NULL;
			new_data->next = NULL;

			if (front == NULL || back == NULL)
			{
				front = new_data;
				back = new_data;
			}
			else
			{
				new_data->next = front;
				front->prev = new_data;
				front = new_data;
			}
		}
		else if (!strcmp(command, "push_back"))
		{
			t_node *new_data;
			new_data = (t_node *)malloc(sizeof(t_node));
			scanf("%d", &data);

			new_data->data = data;
			new_data->prev = NULL;
			new_data->next = NULL;

			if (front == NULL || back == NULL)
			{
				back = new_data;
				front = new_data;
			}
			else
			{
				new_data->prev = back;
				back->next = new_data;
				back = new_data;
			}
		}
		else if (!strcmp(command, "pop_front"))
		{
			if (front == NULL && back == NULL)
				printf("-1\n");
			else
			{
				t_node *temp;
				temp = front;

				printf("%d\n", temp->data);
				front = temp->next;

				free(temp);

				if (front == NULL)
					back = NULL;
				else
					front->prev = NULL;
			}
		}
		else if (!strcmp(command, "pop_back"))
		{
			if (front == NULL && back == NULL)
				printf("-1\n");
			else
			{
				t_node *temp;
				temp = back;

				printf("%d\n", temp->data);
				back = temp->prev;

				free(temp);

				if (back == NULL)
					front = NULL;
				else
					back->next = NULL;
			}
		}
		else if (!strcmp(command, "size"))
		{
			t_node *temp;
			temp = front;

			cnt = 0;
			while (front != NULL && back != NULL && temp != NULL)
			{
				temp = temp->next;
				cnt++;
			}
			printf("%d\n", cnt);
		}
		else if (!strcmp(command, "empty"))
		{
			if (front == NULL && back == NULL)
				printf("1\n");
			else
				printf("0\n");
		}
		else if (!strcmp(command, "front"))
		{
			if (front == NULL)
				printf("-1\n");
			else
				printf("%d\n", front->data);
		}
		else if (!strcmp(command, "back"))
		{
			if (back == NULL)
				printf("-1\n");
			else
				printf("%d\n", back->data);
		}
	}
	return (0);
}
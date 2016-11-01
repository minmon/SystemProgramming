#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

typedef struct
{
	int *event_priority;
	int event_size;
	
	void *(*greeting)();
	void *(*services)();
}Event;

void SingleThread(void *(*function)(void *),void *args);
void *get_event(void *events);
Event compute_void_ptr(void *ptr),event,*ref_ptr;

int hello();
int house_keeping();

int main(void)
{
	int priority[] = {2,1};

	event.event_priority = &*(priority);
	event.event_size = sizeof(priority);

	event.greeting = (void *) &hello;
	event.services = (void *) &house_keeping;
	
	SingleThread(&get_event,&event);
	
	return 0;
}

void SingleThread(void *(*function)(void *),void *args)
{
	pthread_t id=0;
	int size = compute_void_ptr(args).event_size;
	
	while(size--)
	{
		pthread_create(&id,NULL,*function,args);
		pthread_join(id,NULL);
	}
}

void *get_event(void *events)
{
	event = compute_void_ptr(events);
	
	static int i;
	int *priority = event.event_priority;
	
	while(i<event.event_size)
	{
		i++;
		switch(*priority++)
		{
			case 1:
					event.greeting();
					break;
			case 2:
					event.services();
					break;
			default:;
		}		
	}
	return &get_event;
}

Event compute_void_ptr(void *ptr)
{
	(ref_ptr) = (Event *) ptr;
	Event event = *(ref_ptr);
	
	return event;	
}

int hello()
{
	printf("Hello!\n");
	return 0;
}

int house_keeping()
{
	printf("House keeping!\n");
	return 0;
}

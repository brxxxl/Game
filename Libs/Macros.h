#define LIBINITMACRO	{ \
                        if (!al_init()) { \
                            printf ("The allegro5 library is missing."); \
                            return 1; \
                        } \
                        \
                        if (!al_init_primitives_addon()) { \
                            printf ("\nThe allegro_primitives library is missing."); \
                            return 1; \
                        } \
                        \
                        if (!al_init_image_addon()) { \
                            printf ("\nThe allegro_image library is missing."); \
                            return 1; \
                        } \
                        \
                        if (!al_init_acodec_addon()) { \
                            printf ("\nThe allegro_acodec library is missing."); \
                            return 1; \
                        } \
                        }

#define INSTALLMACRO    { \
                        if (!al_install_audio()) { \
                            printf ("Audio cannot be installed. Check your drivers."); \
                            return 1; \
                        } \
                        \
                        if (!al_install_keyboard()) { \
                            printf ("Keyboard cannot be installed. Check your drivers."); \
                            return 1; \
                        } \
                        \
                        if (!al_install_mouse()) { \
                            printf ("Mouse cannot be installed. Check your drivers."); \
                            return 1; \
                        } \
                        }

#define TERMINATE	    { \
                        al_destroy_display(display); \
                        \
                        al_uninstall_audio; \
                        al_uninstall_keyboard; \
                        al_uninstall_mouse; \
                        }

#define EVENTQUEUE	    event_queue = al_create_event_queue(); \
                        \
                        al_register_event_source(event_queue, al_get_display_event_source(display)); \
                        al_register_event_source(event_queue, al_get_keyboard_event_source()); \
                        al_register_event_source(event_queue, al_get_mouse_event_source());

#define DISPLAY         display = al_create_display(width, height);

#define MUSIC(x)        soundtrack = al_load_audio_stream(x,4,44800);

#define VOICEMIXER  	mixer = al_create_mixer(44100, ALLEGRO_AUDIO_DEPTH_FLOAT32, ALLEGRO_CHANNEL_CONF_2); \
				        voice = al_create_voice(44100, ALLEGRO_AUDIO_DEPTH_INT16, ALLEGRO_CHANNEL_CONF_2);

#define TRACKTOVOICE    al_set_audio_stream_playmode(soundtrack, ALLEGRO_PLAYMODE_LOOP); \
                        al_attach_audio_stream_to_mixer(soundtrack, mixer); \
                        al_attach_mixer_to_voice(mixer, voice);

//  End of File
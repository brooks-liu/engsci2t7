hedons = 0
health_points = 0
tired = False
tired_of_stars = False

time_since_run = 121
time_since_textbooks = 121
last_star_time = 121
second_last_star_time = 121
previous_activity = "nothing"
star_activity = "nothing"
previous_activity_length = 0

# this is a second set of variables to run tests
a = 0
b = 0
c = False
d = False

e = 121
f = 121
g = 121
h = 121
i = "nothing"
j = "nothing"
k = 0

hedons_running = 0
hedons_textbooks = 0
hedons_resting = 0


def initialize():
    '''initializes all global variables in the program,
    should be able to run two simulations in the same file (one after the other)'''
    global hedons, health_points, tired, tired_of_stars, previous_activity, previous_activity_length
    global time_since_textbooks, time_since_run, last_star_time, second_last_star_time, star_activity
    global a, b, c, d, e, f, g, h, i, j, k
    global hedons_resting, hedons_running, hedons_textbooks

    hedons = 0
    health_points = 0
    tired = False
    tired_of_stars = False

    previous_activity = "nothing"
    star_activity = "nothing"
    previous_activity_length = 0 
    time_since_run = 121
    time_since_textbooks = 121
    last_star_time = 121
    second_last_star_time = 121

    a = 0
    b = 0
    c = False
    d = False

    e = 121
    f = 121
    g = 121
    h = 121
    i = "nothing"
    j = "nothing"
    k = 0

    hedons_running = 0
    hedons_textbooks = 0
    hedons_resting = 0


def get_cur_hedons():
    '''returns the number of hedons that the user has accumulated so far'''
    global hedons, health_points, tired, tired_of_stars, previous_activity, previous_activity_length
    global time_since_textbooks, time_since_run, last_star_time, second_last_star_time, star_activity
    
    return hedons


def get_cur_health():
    '''returns the number of health points that the user has accumulated so far'''
    global hedons, health_points, tired, tired_of_stars, previous_activity, previous_activity_length
    global time_since_textbooks, time_since_run, last_star_time, second_last_star_time, star_activity
    
    return health_points


def offer_star(activity):
    '''activity is a string of either "running" or "textbooks"'''
    global hedons, health_points, tired, tired_of_stars, previous_activity, previous_activity_length
    global time_since_textbooks, time_since_run, last_star_time, second_last_star_time, star_activity

    if tired_of_stars == True:
        # maybe make a variable called tired_of_stars
        pass
    else:
        last_star_time, second_last_star_time = 0, last_star_time
        star_activity = activity


def star_can_be_taken(activity):
    '''returns True if and only if a star can be used to get MORE hedons for the activity. stars can only be taken
    if the user is not bored of stars AND if it is taken immediately AND the star was offered for that specific activity'''
    global hedons, health_points, tired, tired_of_stars, previous_activity, previous_activity_length
    global time_since_textbooks, time_since_run, last_star_time, second_last_star_time, star_activity

    if last_star_time <= 120 and second_last_star_time <= 120:
        # maybe make a variable called tired_of_stars
        return


def perform_activity(activity, duration):
    '''user performs the activity for a duration (in minutes). if activity is not one of the ones listed, nothing happens.
    assumes minutes are positive integers'''
    global hedons, health_points, tired, tired_of_stars, previous_activity, previous_activity_length
    global time_since_textbooks, time_since_run, last_star_time, second_last_star_time, star_activity

    # globals
    if time_since_run < 120 or time_since_textbooks < 120:
        tired = True

    time_since_run += duration
    time_since_textbooks += duration

    # star + running
    if last_star_time == 0 and star_activity == "running":
        # running

        if activity == "running":    

            # hedons
            if tired == False:
                for i in range(1, duration + 1):
                    if i <= 10:
                        hedons += 5
                    elif i > 10:
                        hedons -= 2
                    else:
                        pass
            elif tired == True:
                for i in range(1, duration + 1):
                    if i <= 10:
                        hedons += 1
                    elif i > 10:
                        hedons -= 2
                    else:
                        pass
            else:
                pass

            # health_points
            if previous_activity == "running":

                last_star_time += duration
                second_last_star_time += duration

                duration += previous_activity_length  # adds the duration if the activity is the same
                for i in range(previous_activity_length + 1, duration + 1):
                    if i <= 180:
                        health_points += 3
                    elif i > 180:
                        health_points += 1
                    else:
                        pass

                previous_activity_length = duration
            else:
                for i in range(1, duration + 1):
                    if i <= 180:
                        health_points += 3
                    elif i > 180:
                        health_points += 1
                    else:
                        pass
                previous_activity_length = duration
                last_star_time += duration
                second_last_star_time += duration   

            #globals
            previous_activity = "running"
            time_since_run = 0


        # textbooks

        elif activity == "textbooks":
            # health_points
            health_points += 2 * duration
            previous_activity_length = duration
            # hedons
            if tired == False:
                for i in range(1, duration + 1):
                    if i <= 20:
                        hedons += 1
                    elif i > 20:
                        hedons -= 1
                    else:
                        pass
            elif tired == True:
                for i in range(1, duration + 1):
                    hedons -= 2
            else:
                pass

            #globals
            previous_activity = "textbooks"
            tired = True
            last_star_time += duration
            second_last_star_time += duration
            time_since_textbooks = 0


        # resting

        elif activity == "resting":
            previous_activity = "resting"
            previous_activity_length = duration
            last_star_time += duration
            second_last_star_time += duration

        else:
            pass
    
    # star + textbooks
    elif last_star_time == 0 and star_activity == "textbooks":
        # running

        if activity == "running":

            # hedons
            if tired == False:
                for i in range(1, duration + 1):
                    if i <= 10:
                        hedons += 2
                    elif i > 10:
                        hedons -= 2
                    else:
                        pass
            elif tired == True:
                for i in range(1, duration + 1):
                    hedons -= 2
            else:
                pass

            # health_points
            if previous_activity == "running":

                last_star_time += duration
                second_last_star_time += duration

                duration += previous_activity_length  # adds the duration if the activity is the same
                for i in range(previous_activity_length + 1, duration + 1):
                    if i <= 180:
                        health_points += 3
                    elif i > 180:
                        health_points += 1
                    else:
                        pass

                previous_activity_length = duration
            else:
                for i in range(1, duration + 1):
                    if i <= 180:
                        health_points += 3
                    elif i > 180:
                        health_points += 1
                    else:
                        pass
                previous_activity_length = duration
                last_star_time += duration
                second_last_star_time += duration       

            #globals
            previous_activity = "running"
            time_since_run = 0


        # textbooks

        elif activity == "textbooks":
            # health_points
            health_points += 2 * duration
            previous_activity_length = duration

            # hedons
            if tired == False:
                for i in range(1, duration + 1):
                    if i <= 10:
                        hedons += 4
                    elif 10 < i <= 20:
                        hedons += 1
                    elif i > 20:
                        hedons -= 1
                    else:
                        pass
            elif tired == True:
                for i in range(1, duration + 1):
                    if i <= 10:
                        hedons += 1
                    elif i > 10:
                        hedons -= 2
                    else:
                        pass
            else:
                pass

            #globals
            previous_activity = "textbooks"
            tired = True
            last_star_time += duration
            second_last_star_time += duration
            time_since_textbooks = 0

        # resting

        elif activity == "resting":
            previous_activity = "resting"
            previous_activity_length = duration
            last_star_time += duration
            second_last_star_time += duration

        else:
            pass
    
    # everything else
    else: 
        # running

        if activity == "running":  

            # hedons
            if tired == False:
                for i in range(1, duration + 1):
                    if i <= 10:
                        hedons += 2
                    elif i > 10:
                        hedons -= 2
                    else:
                        pass
            elif tired == True:
                for i in range(1, duration + 1):
                    hedons -= 2
            else:
                pass

            # health_points
            if previous_activity == "running":

                last_star_time += duration
                second_last_star_time += duration

                duration += previous_activity_length  # adds the duration if the activity is the same
                for i in range(previous_activity_length + 1, duration + 1):
                    if i <= 180:
                        health_points += 3
                    elif i > 180:
                        health_points += 1
                    else:
                        pass

                previous_activity_length = duration
            else:
                for i in range(1, duration + 1):
                    if i <= 180:
                        health_points += 3
                    elif i > 180:
                        health_points += 1
                    else:
                        pass
                previous_activity_length = duration
                last_star_time += duration
                second_last_star_time += duration     


            #globals
            previous_activity = "running"
            time_since_run = 0




        # textbooks

        elif activity == "textbooks":
            # health_points
            health_points += 2 * duration
            previous_activity_length = duration
            # hedons
            if tired == False:
                for i in range(1, duration + 1):
                    if i <= 20:
                        hedons += 1
                    elif i > 20:
                        hedons -= 1
                    else:
                        pass
            elif tired == True:
                for i in range(1, duration + 1):
                    hedons -= 2
            else:
                pass

            #globals
            previous_activity = "textbooks"
            tired = True
            last_star_time += duration
            second_last_star_time += duration
            time_since_textbooks = 0


        # resting

        elif activity == "resting":
            previous_activity = "resting"
            previous_activity_length = duration
            last_star_time += duration
            second_last_star_time += duration

        else:
            pass


def most_fun_activity_minute():
    '''returns the name of the activity that would give the most hedons if it was performed for 1 minute at that instant'''
    global hedons, health_points, tired, tired_of_stars, previous_activity, previous_activity_length
    global time_since_textbooks, time_since_run, last_star_time, second_last_star_time, star_activity

    if tired == True:
        if star_activity == "running":
            return "running"
        elif star_activity == "textbooks":
            return "textbooks"
        else:
            return "resting"
    elif tired == False:
        if star_activity == "running":
            return "running"
        elif star_activity == "textbooks":
            return "textbooks"
        else:
            return "running"
        








if __name__ == "__main__":
    initialize()
    perform_activity("running",1)
    health_points += 3
    offer_star("running")   # CHANGE THIS ONE

    perform_activity("resting",110)    
    offer_star("textbooks")
    perform_activity("running",1)
    health_points += 3
    hedons -= 2
    perform_activity("resting",5)
    offer_star("textbooks")
    perform_activity("textbooks",1)
    print(get_cur_hedons())


    initialize()
    print(most_fun_activity_minute())



if __name__ == "__main__":
    initialize()
    perform_activity("running", 30)
    print(get_cur_hedons()) # -20 = 10 * 2 + 20 * (-2)
    print(get_cur_health()) # 90 = 30 * 3
    perform_activity("resting", 30)
    perform_activity("textbooks", 30)
    print(get_cur_health()) # 150 = 90 + 30*2

    initialize()
    perform_activity("running", 120)
    perform_activity("running", 30)
    perform_activity("running", 50)
    print(get_cur_health())
    
    initialize()
    perform_activity("running", 150)
    perform_activity("textbooks", 1)
    perform_activity("running", 50)
    print(get_cur_health())

    initialize()
    perform_activity("running", 120)
    offer_star("running")
    perform_activity("running", 30)
    offer_star("running")
    perform_activity("running", 50)
    offer_star("running")
    perform_activity("textbooks", 180)
    offer_star("running")

    print("bruh")

    initialize()
    perform_activity("running", 30)
    perform_activity("resting", 30)
    offer_star("running")
    perform_activity("textbooks", 30)
    offer_star("running")
    perform_activity("running", 20)
    perform_activity("running", 170)
    print(get_cur_hedons())


    print("bruh")
    
    initialize()
    perform_activity("running", 30)
    most_fun_activity_minute()

    initialize()
    perform_activity("running", 30)
    perform_activity("resting", 30)
    offer_star("running")
    most_fun_activity_minute()

    initialize()
    perform_activity("running",1)
    print(get_cur_health())
    print(get_cur_hedons())

    initialize()
    perform_activity("textbooks",1)
    print(get_cur_health())
    print(get_cur_hedons())

    initialize()
    print(most_fun_activity_minute())




'''def most_fun_activity_minute():    # Checks current activity that would give the highest number of hedons
    global tired
    global cur_star_activity
    if(tired == True):
        if(cur_starreturn_activity == "running"):
            return "running"
        elif(cur_star_activity == "textbooks"):
            return "textbooks"
        else:
            return "resting"
    else:
        if(cur_star_activity == "running"):
            return "running"
        elif(cur_star_activity == "textbooks"):
            return "textbooks"
        else:
            return "running"'''
import pymysql.cursors

# Connect to the database
connection = pymysql.connect(host='140.134.208.81',
                             port=8762,
                             user='D1050961',
                             password='.5FAzYyP.5vm3wbL',
                             database='D1050961',
                             cursorclass=pymysql.cursors.DictCursor)

with connection:
    print("connect success")
    # with connection.cursor() as cursor:
    #     # Create a new record
    #     sql = "INSERT INTO `users` (`email`, `password`) VALUES (%s, %s)"
    #     cursor.execute(sql, ('webmaster@python.org', 'very-secret'))

    # # connection is not autocommit by default. So you must commit to save
    # # your changes.
    # connection.commit()

    # with connection.cursor() as cursor:
    #     # Read a single record
    #     sql = "SELECT `id`, `password` FROM `users` WHERE `email`=%s"
    #     cursor.execute(sql, ('webmaster@python.org',))
    #     result = cursor.fetchone()
    #     print(result)
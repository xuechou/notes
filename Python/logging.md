# logging module in python3 standard library

## concept

### logging levels

1. CRITICAL
2. ERROR
3. WARNING
4. INFO
5. DEBUG

### todo: logger

### demo 1 : just to replace print()
```py
import logging

logging.basicConfig(level=logging.DEBUG)

logging.critical('this is critical')
logging.error('this is error')
logging.warning('this is warning')
logging.info('this is info')
logging.debug('this is debug')
```

### demo 2 : log to a file

```py
import logging

logging.basicConfig(
    filename = 'xxx.log',
    level=logging.DEBUG,
)

logging.debug('this is debug')
```

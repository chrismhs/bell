# Bell-Air

## Login to particle cloud

```
particle login
```

## Setup

Install particle cli

```
sudo npm install -g particle-cli
```

## Deploy projects

Usage `./deploy.sh [project-folder] [device-id] [device-type 'e' for electron or 'p' for proton]`

```
./deploy.sh bell [device_id] e
```

## Debugging

- connect device through USB
- execute command

```
particle serial monitor
```

## Projects available

### bell

- Bell with speaker

### checks

- WiFi and Cellular network checks

### led

- Led basic test

## Devices available

Check `device-id.txt` file

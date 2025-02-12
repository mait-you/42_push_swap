#!/bin/bash

# Colors for output
GREEN='\033[32m'
BLUE='\033[34m'
RED='\033[31m'
YELLOW='\033[33m'
CYAN='\033[36m'
BOLD='\033[1m'
RESET='\033[0m'
GRAYL='\033[90m'

# Default values and initialization
TESTS_COUNT=${1:-10}
NUMBERS_COUNT=${2:-100}
RANGE_MIN=${3:-1}
RANGE_MAX=${4:-1000}
CHECKER=""

# ASCII Art
print_header() {
    echo -e "${CYAN}"
    echo    "╔══════════════════════════════════════════════════╗"
    echo    "║                 PUSH SWAP TESTER                 ║"
    echo -e "╚══════════════════════════════════════════════════╝${RESET}"
}

# Help message function
show_help() {
    clear
    print_header

    echo -e "\n${BOLD}Usage:${RESET}"
    echo -e "  ./tester.sh ${GRAYL}<TESTS_COUNT> <NUMBERS_COUNT> <RANGE_MIN> <RANGE_MAX>${RESET}"
    echo -e "\n${BOLD}Parameters:${RESET}"
    echo -e "  ${CYAN}TESTS_COUNT${RESET}    Number of tests to run ${GRAYL}(default: 10)${RESET}"
    echo -e "  ${CYAN}NUMBERS_COUNT${RESET}  Numbers per test ${GRAYL}(default: 100)${RESET}"
    echo -e "  ${CYAN}RANGE_MIN${RESET}      Minimum number in range ${GRAYL}(default: 1)${RESET}"
    echo -e "  ${CYAN}RANGE_MAX${RESET}      Maximum number in range ${GRAYL}(default: 1000)${RESET}"
    echo -e "\n${BOLD}Examples:${RESET}"
    echo -e "  ./tester.sh 20 500       ${YELLOW}# Run 20 tests with 500 numbers each${RESET}"
    echo -e "  ./tester.sh 5 100 1 100  ${YELLOW}# Run 5 tests, 100 numbers, range 1-100${RESET}"
    echo
    exit 0
}

# Check for help flags
if [ "$1" == "-h" ] || [ "$1" == "--help" ]; then
    show_help
fi

print_separator() {
    echo -e "${BLUE}━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━${RESET}"
}

# Find available checker
find_checker() {
    local checkers=("./checker_Mac" "./checker" "./checker_linux")
    for checker in "${checkers[@]}"; do
        if [ -x "$checker" ]; then
            CHECKER="$checker"
            return 0
        fi
    done
    return 1
}

# Check if required programs exist
check_requirements() {
    local requirements=("python3" "./push_swap")
    echo -e "\n${BOLD}${BLUE}🔍 Checking Requirements...${RESET}"
    for cmd in "${requirements[@]}"; do
        echo -ne "  ⚙️  Checking for $cmd..."
        if ! command -v $cmd &> /dev/null; then
            echo -e " ${RED}✘${RESET}"
            echo -e "${RED}Error: $cmd is required but not found${RESET}"
            exit 1
        fi
        echo -e " ${GREEN}✔${RESET}"
    done
    
    echo -ne "  ⚙️  Checking for checker..."
    if ! find_checker; then
        echo -e " ${RED}✘${RESET}"
        echo -e "${RED}Error: checker is required but not found${RESET}"
        exit 1
    else
        echo -e " ${GREEN}✔${RESET}"
        echo -e "     ${CYAN}→ Using checker: $CHECKER${RESET}"
    fi
}

# Generate random numbers using Python
generate_numbers() {
    python3 -c "import random; print(' '.join(map(str, random.sample(range($RANGE_MIN, $RANGE_MAX + 1), $NUMBERS_COUNT))))"
}

# Test push_swap with given numbers
test_push_swap() {
    local numbers=$1
    local steps=$(./push_swap $numbers | wc -l)
    local result=$(./push_swap $numbers | ./$CHECKER $numbers)
    
    if [ "$result" != "OK" ]; then
        echo -e "\n${RED}❌ Failed test case:${RESET}"
        echo "Numbers: $numbers"
        echo "Push_swap output:"
        ./push_swap $numbers
        exit 1
    fi
    
    echo $steps
}

# Progress bar
show_progress() {
    local current=$1
    local total=$2
    local percent=$((current * 100 / total))
    local filled=$((percent / 2))
    local unfilled=$((50 - filled))
    
    printf "\r  Progress: ["
    printf "%${filled}s" | tr ' ' '█'
    printf "%${unfilled}s" | tr ' ' '░'
    printf "] %d%%" $percent
}

# Main execution
main() {
    clear
    print_header
    
    # Check requirements first
    check_requirements
    
    local min_steps=0
    local max_steps=0
    local min_test=""
    local max_test=""
    
    echo -e "\n${BOLD}${BLUE}📊 Test Configuration${RESET}"
    echo -e "  •  Number of tests  :${CYAN}$TESTS_COUNT${RESET}"
    echo -e "  •  Numbers per test :${CYAN}$NUMBERS_COUNT${RESET}"
    echo -e "  •  Range            :${CYAN}$RANGE_MIN to $RANGE_MAX${RESET}"
    
    # print_separator
    echo -e "\n${BOLD}${BLUE}🚀 Running Tests...${RESET}\n"
    
    for ((i=0; i<TESTS_COUNT; i++)); do
        numbers=$(generate_numbers)
        steps=$(test_push_swap "$numbers")
        
        # Update min/max values
        if [ $i -eq 0 ] || [ $steps -lt $min_steps ]; then
            min_steps=$steps
            min_test=$numbers
        fi
        
        if [ $i -eq 0 ] || [ $steps -gt $max_steps ]; then
            max_steps=$steps
            max_test=$numbers
        fi
        # show simple progress
        # echo -ne "Progress: $((i+1))/$TESTS_COUNT tests completed\r"
        show_progress $((i+1)) $TESTS_COUNT
    done
    echo -e ""
    # print_separator
    echo -e "\n${BOLD}${BLUE}📈 Test Results${RESET}\n"
    echo -e "  ${GREEN}✓ Minimum Steps:${RESET} $min_steps"
    echo -e "  ${YELLOW}↳ Numbers:${RESET} $min_test"
    echo -e "\n  ${RED}✓ Maximum Steps:${RESET} $max_steps"
    echo -e "  ${YELLOW}↳ Numbers:${RESET} $max_test"
    
    # Calculate and show average
    local avg_steps=$(( (min_steps + max_steps) / 2 ))
    echo -e "\n  ${CYAN}✓ Average Steps:${RESET} $avg_steps"

    echo -e "\n${GREEN}${BOLD}✨ All tests completed successfully! ✨${RESET}\n"
}

# Run the script
main
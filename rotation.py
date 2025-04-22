import random
import json
import os
import datetime
import time
from collections import defaultdict

# Topics with priorities
topics = [
    {"name": "Dynamic Programming (Classical Examples)", "priority": 1},
    {"name": "Greedy Algorithms", "priority": 1},
    {"name": "Complete Search Techniques", "priority": 1},
    {"name": "DFS & Connected Components", "priority": 1},
    {"name": "BFS & Flood Fill", "priority": 1},
    {"name": "Divide and Conquer & Binary Search", "priority": 1},
    {"name": "Segment Trees & Fenwick Trees", "priority": 1},
    {"name": "Number Theory (Prime Numbers, GCD & LCM)", "priority": 2},
    {"name": "Dynamic Programming (Non-Classical Examples)", "priority": 2},
    {"name": "Shortest Paths (BFS for unweighted, Dijkstra's)", "priority": 2},
    {"name": "Bitmask Operations & Techniques", "priority": 2},
    {"name": "Union-Find Disjoint Sets", "priority": 2},
    {"name": "Modular Arithmetic & Combinatorics", "priority": 2},
    {"name": "String Matching & KMP Algorithm", "priority": 2},
    {"name": "Minimum Spanning Trees (Kruskal's & Prim's)", "priority": 3},
    {"name": "Topological Sort & Bipartite Graphs", "priority": 3},
    {"name": "DP with Bitmask & State-Space Search", "priority": 3},
    {"name": "Shortest Paths (Bellman-Ford) & Negative Cycles", "priority": 3},
    {"name": "Network Flow Basics & Two Components Problems", "priority": 3},
    {"name": "Anagrams & Palindromes", "priority": 3},
    {"name": "Basic Geometry & Ternary Search", "priority": 3}
]

# File to store topic history
HISTORY_FILE = "topic_history.json"

def load_history():
    """Load the history of chosen topics from file"""
    if os.path.exists(HISTORY_FILE):
        try:
            with open(HISTORY_FILE, 'r') as f:
                return json.load(f)
        except (json.JSONDecodeError, FileNotFoundError):
            print(f"Error reading history file. Creating new history.")
    return {"last_chosen": {}, "log": []}

def save_history(history):
    """Save the history of chosen topics to file"""
    with open(HISTORY_FILE, 'w') as f:
        json.dump(history, f, indent=2)

def get_eligible_topics(history):
    """
    Determine which topics are eligible to be chosen today based on priority.
    Priority 1: Must not have been reviewed in last 7 days
    Priority 2: Must not have been reviewed in last 14 days
    Priority 3: Must not have been reviewed in last 21 days
    """
    today = datetime.datetime.now().strftime("%Y-%m-%d")
    eligible_topics = []
    
    for topic in topics:
        topic_name = topic["name"]
        priority = topic["priority"]
        last_chosen = history["last_chosen"].get(topic_name, None)
        
        if last_chosen is None:
            eligible_topics.append(topic)
            continue
            
        last_date = datetime.datetime.strptime(last_chosen, "%Y-%m-%d")
        current_date = datetime.datetime.strptime(today, "%Y-%m-%d")
        days_since_last = (current_date - last_date).days
        
        # Check if topic is eligible based on priority
        if (priority == 1 and days_since_last >= 7) or \
           (priority == 2 and days_since_last >= 14) or \
           (priority == 3 and days_since_last >= 21):
            eligible_topics.append(topic)
    
    return eligible_topics

def choose_topic():
    """Choose a topic for today based on priority rules"""
    history = load_history()
    eligible_topics = get_eligible_topics(history)
    
    # If no eligible topics, choose the one with the oldest review date
    if not eligible_topics:
        print("No eligible topics found. Choosing based on oldest review date.")
        oldest_date = datetime.datetime.now()
        oldest_topic = None
        
        for topic in topics:
            topic_name = topic["name"]
            last_chosen = history["last_chosen"].get(topic_name)
            
            if last_chosen:
                date = datetime.datetime.strptime(last_chosen, "%Y-%m-%d")
                if date < oldest_date:
                    oldest_date = date
                    oldest_topic = topic
            else:
                # If any topic has never been chosen, choose it immediately
                oldest_topic = topic
                break
        
        chosen_topic = oldest_topic
    else:
        # Group eligible topics by priority to give higher weights to higher priorities
        priority_groups = defaultdict(list)
        for topic in eligible_topics:
            priority_groups[topic["priority"]].append(topic)
        
        # First try to choose from priority 1
        if priority_groups[1]:
            chosen_topic = random.choice(priority_groups[1])
        # Then try priority 2
        elif priority_groups[2]:
            chosen_topic = random.choice(priority_groups[2])
        # Finally try priority 3
        else:
            chosen_topic = random.choice(priority_groups[3])
    
    # Update history
    today = datetime.datetime.now().strftime("%Y-%m-%d")
    history["last_chosen"][chosen_topic["name"]] = today
    history["log"].append({
        "date": today,
        "topic": chosen_topic["name"],
        "priority": chosen_topic["priority"]
    })
    
    save_history(history)
    return chosen_topic

def print_topic_log(history, days=7):
    """Print log of topics studied in the last {days} days"""
    print(f"\nTopic log (last {days} days):")
    print("=" * 50)
    print(f"{'Date':<12} {'Priority':<10} {'Topic':<40}")
    print("-" * 50)
    
    today = datetime.datetime.now()
    count = 0
    
    # Sort log entries by date, newest first
    sorted_log = sorted(history["log"], key=lambda x: x["date"], reverse=True)
    
    for entry in sorted_log:
        log_date = datetime.datetime.strptime(entry["date"], "%Y-%m-%d")
        days_ago = (today - log_date).days
        
        if days_ago <= days:
            print(f"{entry['date']:<12} {entry['priority']:<10} {entry['topic']:<40}")
            count += 1
    
    if count == 0:
        print("No topics studied in the specified period.")
    print("=" * 50)

def main():
    """Main function to choose a topic for today"""
    history = load_history()
    
    chosen_topic = choose_topic()
    today = datetime.datetime.now().strftime("%Y-%m-%d")
    
    print("\n" + "=" * 50)
    print(f"Today ({today}): {chosen_topic['name']}")
    print(f"Priority: {chosen_topic['priority']}")
    print("=" * 50)
    
    print_topic_log(history)
    
    # Display Next Review Dates
    print("\nNext review dates for each topic:")
    print("=" * 50)
    print(f"{'Topic':<40} {'Last Reviewed':<15} {'Next Review By':<15}")
    print("-" * 50)
    
    for topic in topics:
        name = topic["name"]
        priority = topic["priority"]
        last_review = history["last_chosen"].get(name, "Never")
        
        if last_review != "Never":
            last_date = datetime.datetime.strptime(last_review, "%Y-%m-%d")
            if priority == 1:
                next_date = last_date + datetime.timedelta(days=7)
            elif priority == 2:
                next_date = last_date + datetime.timedelta(days=14)
            else:
                next_date = last_date + datetime.timedelta(days=21)
            next_by = next_date.strftime("%Y-%m-%d")
        else:
            next_by = "ASAP"
        
        print(f"{name:<40} {last_review:<15} {next_by:<15}")
    
    print("=" * 50)

if __name__ == "__main__":
    main()